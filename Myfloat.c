#include "Myfloat.h"
#include <stdio.h>

float construct_float_sf(char sign_bit, char exponent, unsigned int fraction) {
   unsigned int f = 0;

   /*
    * Start coding here
    * Use bitwise operations to construct the IEEE 754 float
    */

   int sign= ((unsigned int) sign_bit) & 0x00000001;
   sign<<=31;

   int power= ((unsigned int) exponent) & 0x000000FF;
   power<<=23;

   int mantissa= ((unsigned int) fraction) & 0x7FFFFFFF;

   f = sign | power | mantissa;

   return *(float *)&f;
}
