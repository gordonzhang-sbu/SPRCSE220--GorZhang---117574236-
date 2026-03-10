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
    //If we destination has size of 0, we have nothing to copy to
    if (size == 0){
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
    int i=0;

    //Loop while the string is not null
    while (s[0] != '\0'){
        //Get the current char
        char currentChar = s[i];
        
        //Store true or false value in isLetter regarding whether cuurent char is a letter or not
        int isLetter = ((currentChar >= 'A' && currentChar <= 'Z') || (currentChar >= 'a' && currentChar <= 'z'));

        //Make sure the current char is not the left most
        //Make sure the neighbor is somewhere between 0 and 9
        int leftIsANumber = ( i > 0 && (s[i-1] >='0' && s[i-1] <='9'));

        //Since the right most is always null, we don't need to check it
        //Make sure the neighbor is somewhere between 0 and 9
        int rightIsANumber = (s[i+1] >='0' && s[i+1] <='9');

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
    }

}

int strgDiff(const char *s1, const char *s2) {
    (void)s1;
    (void)s2;
    /* TODO */
    return 0;
}

void strgInterleave(const char *s1, const char *s2, char *d, size_t size) {
    (void)s1;
    (void)s2;
    (void)d;
    (void)size;
    /* TODO */
}

void strgReverseLetters(char *s) {
    (void)s;
    /* TODO */
}
