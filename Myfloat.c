#include "Myfloat.h"
#include <stdio.h>

int main(){
   printf("Test Correctness: ");
   printf("f = %g\n", construct_float_sf(0x00, 0x76, 0x299B6F));
   printf("\n");
}

float construct_float_sf(char sign_bit, char exponent, unsigned int fraction) {
   unsigned int f = 0;

   /*
    * Start coding here
    * Use bitwise operations to construct the IEEE 754 float
    */

   //Ensure bits is not negative, and only get the first bit
   int sign= ((unsigned int) sign_bit) & 0x00000001;
   //Move it to position 31
   sign<<=31;

   //Ensure bits is not negative, and get the last 8 bits
   int power= ((unsigned int) exponent) & 0x000000FF;
   //Move it to the right position which is 30-23
   power<<=23;

   //Ensure bits is not negative, and get the last 23 bits
   int mantissa= ((unsigned int) fraction) & 0x007FFFFF;

   //Combine them
   f = sign | power | mantissa;

   return *(float *)&f;
}
