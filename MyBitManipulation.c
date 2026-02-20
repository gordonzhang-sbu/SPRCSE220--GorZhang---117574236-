// HW3 Starter Code
#include "MyBitManipulation.h"
#include <stdio.h>


int main(){
   printf("ToggleBit Test\n");
   printf("Test 1: %d\n",ToggleBit(0,3));
   printf("Test 2: %d\n",ToggleBit(1,31));
   printf("Test 3: %d\n",ToggleBit(-2147483647,0));
   printf("Test 4: %d\n",ToggleBit(0,0));
   printf("\n");

   printf("GetMSB Test\n");
   printf("Test 1: %d\n",GetMSB(2147483647));
   printf("Test 2: %d\n",GetMSB(-2147483647));
   printf("Test 3: %d\n",GetMSB(0));
   printf("Test 4: %d\n",GetMSB(-1));
   printf("\n");

   printf("ClearBitRange Test\n");
   printf("Test 1: %d\n",ClearBitRange(0,0,31));
   printf("Test 2: %d\n",ClearBitRange(-2147483647,31,31));
   printf("Test 3: %d\n",ClearBitRange(2147483647,31,0));
   printf("Test 4: %d\n",ClearBitRange(2147483647,0,31));
   printf("\n");

   printf("RotateLeft Test\n");
   printf("Test 1: %d\n",RotateLeft(-2147483647,-1));
   printf("Test 2: %d\n",RotateLeft(1,31));
   printf("Test 3: %d\n",RotateLeft(-1,31));
   printf("Test 4: %d\n",RotateLeft(-2147483647,32));
   printf("\n");

   printf("SwapOddEvenBits Test\n");
   printf("Test 1: %d\n",SwapOddEvenBits(0));
   printf("Test 2: %d\n",SwapOddEvenBits(0xFFFFFFFF));
   printf("Test 3: %d\n",SwapOddEvenBits(1));
   printf("Test 4: %d\n",SwapOddEvenBits(0x80000000));

   return 0;
}


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
   int result=-1;

   //Cast num to unsigned to ensure no negative
   unsigned int temp= (unsigned int) num;

   //Loop over the digit by dividing by 2, each iteration adds one to the result, until reach the end
   while (temp!=0){
      temp/=2;
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
   
   for (int i=0; i<d; i++){
      //Get the left most bit
      int MSB=(num & 0x80000000);
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
