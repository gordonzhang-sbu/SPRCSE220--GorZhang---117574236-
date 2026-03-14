#include "strgPtr.h"
/* DO NOT use <string.h> or <ctype.h> */

int strgLen(const char *s) {
    (void)s;
    /* TODO */
    //If the memory
    if (s == NULL) {
        return -1;
    }

    int result=0;

    //While the value of s is not a null
    while (*s++){
        result++;
    }

    return result;
}

void strgCopy(const char *source, char *destination, size_t size) {
    (void)source;
    (void)destination;
    (void)size;
    /* TODO */
    //If we destination has size of 0 or less, we have nothing to copy to
    if (size <= 0){
        return;
    }
    if (source == NULL || destination == NULL){
        return;
    }

    size_t i=0;
    //Loop until size-1 since we need the last char to be null
    for (; i<size-1; i++){
        //If there is a null in source then it means we loop all the char already so stop
        if (source[i] == '\0'){
            break;
        }
        //Set the char at index i of destination equals to the char at index i of source
        destination[i] = source[i];
    }
    //Add the null
    destination[i] ='\0';


    
}

void strgChangeCase(char *s) {
    (void)s;
    /* TODO */
    if (s == NULL){
        return;
    }

    int i=0;

    //Loop while the string is not null
    while (s[i] != '\0'){
        //Get the current char
        char currentChar = s[i];
        
        //Store true or false value in isLetter regarding whether cuurent char is a letter or not
        int isLetter = ((currentChar >= 'A' && currentChar <= 'Z') || (currentChar >= 'a' && currentChar <= 'z'));

        //Since the right most is always null, we don't need to check it
        //Make sure the neighbor is somewhere between 0 and 9
        int rightIsANumber = (s[i+1] >='0' && s[i+1] <='9');

        //Make sure the current char is not the left most
        //Make sure the neighbor is somewhere between 0 and 9
        int leftIsANumber = ( i > 0 && (s[i-1] >='0' && s[i-1] <='9'));



        //If the currentChar is a letter and neither neighbor is a number
        if (isLetter && !leftIsANumber && !rightIsANumber){
            //Check whether upper case or lower case
            if ((currentChar >= 'A' && currentChar <= 'Z')){
                //If upper case add 32 (Since on ASCII, upper and lower case has a difference of 32)
                s[i] = currentChar + 32;
            } else {
                //If lower case minus 32 (Since on ASCII, upper and lower case has a difference of 32)
                s[i] = currentChar - 32;
            }
        }

        i++;
    }
    


}

int strgDiff(const char *s1, const char *s2) {
    (void)s1;
    (void)s2;
    /* TODO */
    //If any of the strings is null then return -2
    if (s1 == NULL || s2 == NULL){
        return -2;
    }

    int i=0;
    //While we have not reached a null
    while (s1[i] != '\0' && s2[i] != '\0'){
        //If we find a difference
        if (s1[i] != s2[i]) {
            return i;
        }
        //Move to next char
        i++;
    }

    //In case we reach only one end but not both end
    if (s1[i] != s2[i]) {
        return i;
    }

    //If identical
    return -1;
}

void strgInterleave(const char *s1, const char *s2, char *d, size_t size) {
    (void)s1;
    (void)s2;
    (void)d;
    (void)size;
    /* TODO */

    //Do nothing if any of these parameters is null
    if (s1 == NULL || s2 == NULL || d == NULL){
        return;
    }
    if (size == 0){
        return;
    }

    //Index of s1, s2, and d
    size_t s1I = 0;
    size_t s2I = 0;
    size_t dI = 0;

    //While we are not reaching the second to the last index of d
    //And there is still more to traverse in either strings
    while (dI < size -1 && (s1[s1I] != '\0' || s2[s2I] != '\0')){
        //If there is still more s1 to traverse
        if (s1[s1I] != '\0'){
            //If there is more room to put in
            if (dI < size - 1){
                d[dI++] = s1[s1I++];
            }
        }

        //If there is still more s2 to traverse
        if (s2[s2I] != '\0'){
            //If there is more room to put in
            if (dI < size - 1){
                d[dI++] = s2[s2I++];
            }
        }



    }

    //Make the last char a null
    d[dI] = '\0';


}

void strgReverseLetters(char *s) {
    (void)s;
    /* TODO */
    if (s == NULL){
        return;
    }

    //Loop to find the length of the string
    int len = 0;
    for (int i=0; s[i] != '\0'; i++){
        len++;
    }

    //Cursor for left and right (minus 1 since last char is Null) char
    int left = 0;
    int right = len - 1;

    //Loop through the string until both left and right cursor meet
    for (; left < right ; ){
        //Check if the current left char is a char, if not char, then skip it
        if (! ((s[left] >= 'A' && s[left] <= 'Z') || (s[left] >= 'a' && s[left] <= 'z'))){
            left++;
            continue;
        }
        //Check if the current right char is a char, if not char, then skip it
        if (! ((s[right] >= 'A' && s[right] <= 'Z') || (s[right] >= 'a' && s[right] <= 'z'))){
            right--;
            continue;
        }

        //temp variable to store current left char
        char temp = s[left];
        //Swap left and right
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;

    }
    
}
