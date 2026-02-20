#include "MyIntegers.h"
#include <stdio.h>
#include <stdbool.h>

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
    }
    if (target_repr!='2' && target_repr!='S'){
        printf("error\n");
    }
    if (source_repr==target_repr){
        printf("%08x\n",repr);
    }

    int reprVal=0;

    if (source_repr=='2'){
        reprVal = (int) repr;
    } else {
        unsigned int sign = repr >> 31;
        unsigned int value = repr & 0x7FFFFFFF;

        if (sign != 0){
            if (value == 0){
                reprVal = (int) value;
            } else {
                reprVal = (int) value;
                reprVal = -reprVal;
            }
        } else {
            reprVal = (int) value;
        }
    }

    unsigned int result = 0;

    if (target_repr == '2'){
        result= (unsigned int) reprVal;
    } else {
        if (reprVal == (-2147483647 - 1)){
            printf("undefined\n");
            return;
        }

        if (reprVal < 0){
            unsigned int value = (unsigned int) (-value);
            result = 0x80000000;
            result |= value;
        } else {
            result = (unsigned int) reprVal;
        }

        if (result == 0x80000000){
            result=0;
        }
    }

    printf("%08x\n",result);





}
