#include <stdio.h>
#include "MyBitManipulation.h"
#include "Myfloat.h"
#include "MyIntegers.h"

int main(void) {

   /* PART 1: Bit Manipulation Tests */
   printf("ToggleBit(9, 0) = %d\n", ToggleBit(9, 0));
   printf("GetMSB(18) = %d\n", GetMSB(18));

   /* PART 2: Float Construction */
   float f = construct_float_sf(0x00, 0x7F, 0x200000);
   printf("Float value = %g\n", f);

   /* PART 3: Integer Representation Conversion */
   repr_convert('2', '2', 0x59f2ca50);

   return 0;
}
