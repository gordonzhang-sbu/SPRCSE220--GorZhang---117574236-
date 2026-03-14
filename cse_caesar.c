#include "cse_caesar.h"
#include "strgPtr.h"
/* DO NOT use <string.h> or <ctype.h> */

int encryptCaesar(const char *plaintext, char *ciphertext, int key) {
    (void)plaintext;
    (void)ciphertext;
    (void)key;
    /* TODO */

    //If either text is null then return -2
    if(plaintext == NULL) {
        return -2;
    }
    if (ciphertext == NULL) {
        return -2;
    }

    //Get the length of the cipher text
    int ciphertextLen = 0;
    for (;ciphertext[ciphertextLen] != '\0';){
        ciphertextLen++;
    }

    //There need at least 7 char to store __EOM__, else return -1
    if (ciphertextLen < 7){
        return -1;
    }

    int result = 0;
    
    int i = 0;
    //Loop through the plain text
    for (i = 0; plaintext[i] != '\0'; i++){
        //If there is no more room for __EOM__, break the loop
        if (ciphertextLen - 7 <= i){
            break;
        }

        char currentChar = plaintext[i];
        int shiftBy = key + i;

        //If current char is a captial letter
        if (currentChar >= 'A' && currentChar <= 'Z'){
            //Current char minus A such that we have a range from 0 to 25
            //Then we shift the char by the key + index
            //Mod 26 to wrap around
            //Plus A so that we have the correct ASCII
            char newChar = ((currentChar - 'A' + shiftBy) % 26) + 'A';
            ciphertext[i] = newChar;
            result++;
        } else if (currentChar >= 'a' && currentChar <= 'z'){
            //Similar to the upper case if statments
            char newChar = ((currentChar - 'a' + shiftBy) % 26) + 'a';
            ciphertext[i] = newChar;
            result++;
        } else if (currentChar >= '0' && currentChar <= '9'){
            //In the case of number, add the shift, which is equal to key + 2 * index and mod 10 to wrap around
            ciphertext[i] = ((currentChar - '0' + (key + 2 * i)) %10) + '0';
            result++;
        } else {
            //This case is for punctuation, space, etc.
            ciphertext[i] = currentChar;
        }

        
        
    }

    //Add the marker in the end of the ciphertext
    char marker[] = "__EOM__";
    for (int j = 0; j<7; j++){
        ciphertext[i+j] = marker[j];
    }

    //Add the null terminator
    ciphertext[i + 7] = '\0';
    


    return result;
}

int decryptCaesar(const char *ciphertext, char *plaintext, int key) {
    (void)ciphertext;
    (void)plaintext;
    (void)key;
    /* TODO */
    //If either text is null then return -2
    if(plaintext == NULL) {
        return -2;
    }
    if (ciphertext == NULL) {
        return -2;
    }
    //Get the length of the plaintext
    int plaintextLen = strgLen(plaintext);
    if (plaintextLen == 0) {
        return 0;
    }
    //Check if there is an EOM marker
    int thereIsEOM = 0;
    //Loop through the string and check at every index if there is an EOM marker
    for (int i = 0; ciphertext[i] != '\0'; i++){
        if (hasEOM(ciphertext, i)){
            thereIsEOM = 1;
            break;
        }
    }
    //If no EOM marker, return -1
    if (!thereIsEOM){
        return -1;
    }

    

    //Cursor for ciphertext index and plaintext index
    int cI = 0;
    int pI = 0;
    int result = 0;

    while (ciphertext[cI] != '\0'){

        //If the EOM marker appears , then just return 
        if (hasEOM(ciphertext, cI)){
            plaintext[pI] = '\0';
            return result;
        }

        char currentChar = ciphertext[cI];
        int shift = (key + cI);

        //If currentChar is capital
        if (currentChar >= 'A' && currentChar <= 'Z'){
            //Current char minus A such that we have a range from 0 to 25
            //Then we shift the char "back" by the key + index
            //Mod 26 to wrap around
            //Plus A so that we have the correct ASCII
            plaintext[pI] = (currentChar - 'A' - shift + 26) % 26 + 'A';
            result++;
        } else if (currentChar >= 'a' && currentChar <= 'z') {
            //Similar to the above
            plaintext[pI] = (currentChar - 'a' - shift + 26) % 26 + 'a';
            result++;
        } else if (currentChar >= '0' && currentChar <= '9'){
            //In the case of number, minus the shift, which is equal to key + 2 * index and mod 10 to wrap around
            int shiftNum = key + 2 * cI;
            plaintext[pI] = (((currentChar - '0' - shiftNum) % 10) + 10) % 10 + '0';
            result++;
        } else {
            //In the case of other special char
            plaintext[pI] = currentChar;
        }

    
        cI++;
        pI++;

    }

    plaintext[pI] = '\0';

    


    return -1;
}

//A helper method that return 1 if __EOM__ starts at index, else return 0
int hasEOM(const char *string, int index){
    int result = 0;
    if (string[index] == '_' && string[index+1] == '_' && string[index+2] == 'E'){
        if (string[index+3] == 'O' && string[index+4] == 'M' && string[index+5] == '_'){
            if (string[index+6] == '_'){
                return 1;
            }
        }
    }

    return result;
}
