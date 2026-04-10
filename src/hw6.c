/*
Name: Gordon Zhang
SBU ID: 117574236
*/
#include "hw6.h"

int main(int argc, char *argv[]) {

    //Part 1

    //Case 1
    //Check if the arguments is at least 7
    if (!(argc >= 7)){
        return MISSING_ARGUMENT;
    }

    //Case 2
    //Check for duplicate
    //Variables to count the appearance of each command
    int sCount = 0;
    int rCount = 0;
    int lCount = 0;
    int wCount = 0;
    //Pointer for the input after the command
    char *searchFor = NULL;
    char *replaceWith = NULL;
    char *lines = NULL;
    //Loops through the array from 1 to array length - 2
    for (int i = 1; i < argc - 2; i++){

        //Check if any of element in the array is equal (char comparison so use strcmp) to the -s command
        if (strcmp(argv[i], "-s") == 0){
            //If there is already a s there cannot be another some command
            if (sCount){
                return DUPLICATE_ARGUMENT;
            }
            //Have not seen a s yet, then plus one count
            sCount++;

            //Two cases
            //Nothing after the command
            //The command follows by another command directly
            if ((i + 1 >= argc -2) || argv[i+1][0] == '-' ){
                return S_ARGUMENT_MISSING;
            }

            //If there is an argument follow by the command assign it to searchFor
            searchFor = argv [++i];
        } else if (strcmp(argv[i], "-r") == 0){
            //Similar as above yet for -r command
            if (rCount){
                return DUPLICATE_ARGUMENT;
            }
            rCount++;
            if ((i + 1 >= argc -2) || argv[i+1][0] == '-' ){
                return R_ARGUMENT_MISSING;
            }
            replaceWith = argv [++i];
        } else if (strcmp(argv[i], "-l") == 0){
            //Similar as above yet for -l command
            if (lCount){
                return DUPLICATE_ARGUMENT;
            }
            lCount++;
            if ((i + 1 >= argc -2) || argv[i+1][0] == '-' ){
                return L_ARGUMENT_INVALID;
            }
            lines = argv [++i];
        } else if (strcmp(argv[i], "-w") == 0){
            if (wCount){
                return DUPLICATE_ARGUMENT;
            }
            wCount++;
        }
    }


    //Case 3
    //If we cannot open an input file to read because the input file is missing
    FILE *input = fopen(argv[argc-2], "r");
    if (!input){
        return INPUT_FILE_MISSING;
    }

    //Case 4
    //If we cannot open an output file to write because the output file is missing
    FILE *output = fopen(argv[argc-1], "w");
    if (!output){
        fclose(input);
        return OUTPUT_FILE_UNWRITABLE;
    }

    //Case 5, 6
    if (sCount == 0 || searchFor == NULL){
        fclose(input);
        fclose(output);
        return S_ARGUMENT_MISSING;
    }
    if (rCount == 0 || replaceWith == NULL){
        fclose(input);
        fclose(output);
        return R_ARGUMENT_MISSING;
    }

    int startAt = 1;
    int endAt = 100;
    //Case 7
    if (lCount){
        //Make a copy of the lines input
        char temp[100];
        strcpy(temp,lines);

        //Split up the inputs for -l command into two, one for the start, and one for the end
        char *startStr = strtok(temp,",");
        char *endStr = strtok(NULL, "," );

        //If missing any of the start or end
        if (!startStr || !endStr){
            fclose(input);
            fclose(output);
            return L_ARGUMENT_INVALID;
        }

        //Parse the string into long and store them into the corresponding pointer
        char *startStrEnd;
        char *endStrEnd;
        long start = strtol(startStr, &startStrEnd, 10);
        long end = strtol(endStr, &endStrEnd, 10);

        //If we did not find any digit to parse, or the pointer does not move at all
        if (startStrEnd == startStr){
            fclose(input);
            fclose(output);
            return L_ARGUMENT_INVALID;
        }
        if (endStrEnd == endStr){
            fclose(input);
            fclose(output);
            return L_ARGUMENT_INVALID;
        }

        //If start is greater than end
        if (start > end){
            fclose(input);
            fclose(output);
            return L_ARGUMENT_INVALID;
        }

        startAt = (int)start;
        endAt = (int)end;
    }

    //Case 8
    int isPrefix = 0;
    int isSuffix = 0;
    char originalWord[MAX_SEARCH_LEN];
    strcpy(originalWord,searchFor);

    if (wCount){

        int wordLength = strlen(originalWord);
        int starCount = 0;

        //Check to see if two star is in the argument -s provided
        for (int i = 0; i < wordLength; i++){
            if (originalWord[i] == '*'){
                starCount++;
            }
        }

        //If more than one then invalid
        if (starCount != 1){
            fclose(input);
            fclose(output);
            return WILDCARD_INVALID;
        }


        //If the argument -s provided ends with *, it is a prefix
        if (originalWord[wordLength - 1] == '*'){
            isPrefix = 1;
            originalWord[wordLength - 1] = '\0';

            //If user only provided with one star
            if (strlen(originalWord) == 0){
                fclose(input);
                fclose(output);
                return WILDCARD_INVALID;
            }
        } else if (originalWord[0] == '*'){
            //If the argument -s provided starts with *, it is a suffix
            isSuffix = 1;

            //If user only input one star
            if (wordLength == 1){
                fclose(input);
                fclose(output);
                return WILDCARD_INVALID;
            }

            //Shift the word forward
            int j = 0;
            for (int i = 1; originalWord[i] != '\0'; i++){
                originalWord[j++] = originalWord [i];
            }
            originalWord[j] = '\0';

            //If user only input one star
            if (strlen(originalWord) == 0){
                fclose(input);
                fclose(output);
                return WILDCARD_INVALID;
            }
        
        } else {
            fclose(input);
            fclose(output);
            return WILDCARD_INVALID;
        }
    }


    char buffer[MAX_LINE];
    int inLine = 1;

    //Loop through the text file while not reaching the end marker or maxing buffer 
    while (fgets(buffer, sizeof(buffer),input)){
        //If we are not in the safe zone that -l command provides
        if (inLine < startAt || inLine > endAt){
            //We just copy everthing from buffer into output
            fputs(buffer,output);
        } else {
            char result[MAX_LINE];
            result[0] = '\0';

            //If we do not provided with a w
            if (!wCount){
                char *currentPosition = buffer;
                char *targetAt = NULL;
                int searchWordLength = strlen(searchFor);

                //Starting at the currenposition, find the first occurance of the word we search for
                //If targetAt is not NULL, means there is a word we search for after the currentposition, we keep looping
                while ((targetAt = strstr (currentPosition, searchFor)) != NULL){
                    //Copy or concat all the line from currentposition up to but not including the targer word
                    strncat(result, currentPosition, targetAt-currentPosition);
                    //Add the replace word
                    strcat(result,replaceWith);
                    //Advance the currentposition from where the target is plus the word we search for
                    currentPosition = targetAt + searchWordLength;
                }

                //Copy whatever is left over
                //Put the result in the output file
                strcat(result,currentPosition);
                fputs(result,output);
            } else {
                char *currentPositionW = buffer;
                //If we have not reach the end of the file
                while (*currentPositionW){

                    //If the current postion char is just any punctuation/space
                    if (!isalnum(*currentPositionW)){
                        //Just copy over the char
                        strncat(result,currentPositionW,1);
                        //Advance to the next char
                        currentPositionW++;
                        continue;
                    } 

                    //If the current char is an actual char
                    char word[MAX_SEARCH_LEN];
                    int i = 0;
                    while (isalnum(*currentPositionW)){
                        word[i] = *currentPositionW;
                        i++;
                        currentPositionW++;
                    } 
                    //Store the words
                    word[i] = '\0';

                    int hasTarget = 0;
                    int searchWordLength = strlen(originalWord);

                    //If we know there is a prefix
                    if (isPrefix){
                        //If the word has a substring the search word at index of 0
                        if (strncmp(word, originalWord, searchWordLength) == 0){
                            hasTarget = 1;
                        }
                    } else if (isSuffix) {
                        //If the word has a substrings of the search word at the second last index
                        if ((int)strlen(word) >= searchWordLength && strcmp(word + strlen(word) - searchWordLength, originalWord) == 0){
                            hasTarget = 1;
                        }
                    }

                    //If has target replace with the word
                    if (hasTarget){
                        strcat(result, replaceWith);
                    } else {
                    //If no target found just append the word
                        strcat(result, word);
                    }
                }
                //Puts the result onto output
                fputs(result, output);
            }
        }
        //Move to the next line
        inLine++;
    }

    fclose(input);
    fclose(output);

    return 0;
}
