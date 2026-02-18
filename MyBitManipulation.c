// HW3 Starter Code
#include "MyBitManipulation.h"
#include <stdio.h>

/*
* Toggle the bit at position pos in num
*/
int ToggleBit(int num, int pos) {
   /* TODO: implement */
   int masking=1;
   for (int i=0; i<pos; i++){
      masking*=2;
   }
   return num ^ masking; 
}

/*
* Return the position of the most significant set bit
* Return -1 if num == 0
*/
int GetMSB(int num) {
   /* TODO: implement */
   int result=-1;

   

   while (num>0){
      num=num/2;
      result++;
   }
   if (result==-1){
      return result;
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
   
   for (int i=start; i<=end; i++){
      int mask= ~(1<<i);

      num &= mask; 
   }

   return num;
}

/*
* Rotate num to the left by d bits
*/
uint32_t RotateLeft(uint32_t num, int d) {
   /* TODO: implement */
   
   for (int i=0; i<d; i++){
      //Get the left most bit
      int MSB=(num & 800000000);
      //Shift it to the right
      MSB >>=31;

      //Shift all the bit to the left by 1
      num = num <<1;
      // Add the left most bit to the right
      num= num | MSB;

   }


   return num;
}

/*
* Swap odd and even bits
*/
int SwapOddEvenBits(int num) {
   /* TODO: implement */
   int evenMask=0xAAAAAAAAA;
   int oddMask=0x55555555;

   int even= num & evenMask;
   int odd= num & oddMask;

   even>>=1;
   odd<<=1;

   int result=even|odd;

   return result;
}
