#include "MyIntegers.h"
#include <stdio.h>
#include <stdbool.h>

/*
int main(){
    printf("Test 1: ");
    repr_convert('2','S',0);
    printf("\n");
    
    printf("Test 2: ");
    repr_convert('2','S',5);
    printf("\n");

    printf("Test 3: ");
    repr_convert('2','S',-5);
    printf("\n");

    printf("Test 4: ");
    repr_convert('S','2',5);
    printf("\n");

    printf("Test 5: ");
    repr_convert('S','2',-5);
    printf("\n");

    printf("Test 6: ");
    repr_convert('2','S',0x80000000);
    printf("\n");

    printf("Test 7: ");
    repr_convert('2','2',0x80000000);
    printf("\n");

    printf("Test 8: ");
    repr_convert('S','S',0x80000000);
    printf("\n");

    printf("Test 9: ");
    repr_convert('X','S',0x80000000);
    printf("\n");

    printf("Test 10: ");
    repr_convert('S','4',0x80000000);
    printf("\n");

}
*/

void repr_convert(char source_repr, char target_repr, unsigned int repr) {

   /*
    * TODO:
    * 1. Validate source_repr and target_repr
    * 2. Decode the source representation
    * 3. Convert to target representation
    * 4. Print the result or error message
    */

    //Constraints
    if (source_repr!='2' && source_repr !='S'){
        printf("error\n");
        return;
    }
    if (target_repr!='2' && target_repr!='S'){
        printf("error\n");
        return;
    }
    if (source_repr==target_repr){
        printf("%08x\n",repr);
        return;
    }

    int reprVal=0;

    //Check source representation
    if (source_repr=='2'){
        reprVal = (int) repr;
    } else {
        //Get the sign of the repr
        unsigned int sign = repr >> 31;
        //Get the value of the repr
        unsigned int value = repr & 0x7FFFFFFF;

        //If sign is negative
        if (sign != 0){
            //If value is zero
            if (value == 0){
                reprVal = (int) value;
            } else {
                reprVal = (int) value;
                reprVal = -reprVal;
            }
        } else {
            //If sign is positive
            reprVal = (int) value;
        }
    }

    unsigned int result = 0;

    //Check the target representation
    if (target_repr == '2'){
        //If target_repr is just 2, just return the reprVal
        result= (unsigned int) reprVal;
    } else {
        //The number in source representation cannot be represented in the target representation so just return undefined
        if (reprVal == -2147483648){
            printf("undefined\n");
            return;
        }

        //If reprVal is negative
        if (reprVal < 0){
            //Take just the value of reprVal
            unsigned int value = (unsigned int) (reprVal);
            result = 0x80000000;
            //Make it negative
            result |= value;
        } else {
            //Just take the positive value
            result = (unsigned int) reprVal;
        }


    }

    printf("%08x\n",result);





}
