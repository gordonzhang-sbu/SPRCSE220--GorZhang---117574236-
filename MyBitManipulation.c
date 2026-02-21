// HW3 Starter Code
#include "MyBitManipulation.h"
#include <stdio.h>


/*
* Toggle the bit at position pos in num
*/
int ToggleBit(int num, int pos) {
   /* TODO: implement */
   int masking=1;
   //Shift the mask by pos digit to the right by times 2 every time
   for (int i=0; i<pos; i++){
      masking*=2;
   }

   //Exclusive or
   return num ^ masking; 
}




/*
* Return the position of the most significant set bit
* Return -1 if num == 0
*/
int GetMSB(int num) {
   /* TODO: implement */
   if (num == 0) {
      return -1;
   }

   //Cast num to unsigned to ensure no negative
   unsigned int temp = (unsigned int) num;
   int result=0;

   //Loop over the digit, each iteration adds one to the result, until reach the end
   while (temp >>= 1){
      result++;
   }


   return result;
}

/*
* Clear bits from start to end (inclusive)
*/
int ClearBitRange(int num, int start, int end) {
   /* TODO: implement */

   //Constraints
   if (start < 0 || end > 31 || start > end){
      return num;
   }
   
   //Start from start digit to the end digit
   for (int i=start; i<=end; i++){
      //Move the mask to the i position and negate it
      int mask= ~(1<<i);

      //Use & operation to clear the bit
      num &= mask; 
   }

   return num;
}

/*
* Rotate num to the left by d bits
*/
uint32_t RotateLeft(uint32_t num, int d) {
   /* TODO: implement */
   d=d % 32;
   //Shift num to the left by 32 -d
   //Shift num to the right by d
   //We combine left with right so we know what is fell out during the rotation
   return ((num << d) | (num >> (32-d)));
}

/*
* Swap odd and even bits
*/
int SwapOddEvenBits(int num) {
   /* TODO: implement */
   int evenMask=0xAAAAAAAA;
   int oddMask=0x55555555;

   //Mask the num using evenMask and save the pattern to even
   int even= num & evenMask;
   //Mask the num using oddMask and save the pattern to odd
   int odd= num & oddMask;

   //Shift even right by 1 and odd left by 1 so we can switch the even bit and odd bit
   even>>=1;
   odd<<=1;

   //Use or operation to combine them
   int result=even|odd;

   return result;
}
