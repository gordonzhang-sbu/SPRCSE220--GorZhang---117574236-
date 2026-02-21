#include <criterion/criterion.h>
#include "MyBitManipulation.h"
#include "Myfloat.h"
#include "MyIntegers.h"

/* =========================
* PART 1: Bit Manipulation
* ========================= */

Test(ToggleBit, examples) {
   cr_assert_eq(ToggleBit(9, 0), 8);
   cr_assert_eq(ToggleBit(9, 3), 1);

   cr_assert_eq(ToggleBit(0, 31), -2147483648);
   cr_assert_eq(ToggleBit(5, 0), 4);
   cr_assert_eq(ToggleBit(5, 2), 1);
   cr_assert_eq(ToggleBit(0, 0), 1);
   cr_assert_eq(ToggleBit(-1, 31), 2147483647);
   cr_assert_eq(ToggleBit(0, 15), 32768);
   cr_assert_eq(ToggleBit(1, 0), 0);
}

Test(GetMSB, examples) {
   cr_assert_eq(GetMSB(18), 4);
   cr_assert_eq(GetMSB(0), -1);
   cr_assert_eq(GetMSB(2), 1);
   cr_assert_eq(GetMSB(0x80000000), 31);
   cr_assert_eq(GetMSB(0x0), -1);
   cr_assert_eq(GetMSB(1), 0);
   cr_assert_eq(GetMSB(0xFFFFFFFF), 31);
   cr_assert_eq(GetMSB(-1), 31);
}

Test(ClearBitRange, examples) {
   cr_assert_eq(ClearBitRange(73, 1, 3), 65);
   cr_assert_eq(ClearBitRange(0,0,31),0);
   cr_assert_eq(ClearBitRange(-2147483647,31,31), 1);
   cr_assert_eq(ClearBitRange(2147483647,31,0), 2147483647);
   cr_assert_eq(ClearBitRange(2147483647,0,31), 0);


}

Test(RotateLeft, examples) {
   cr_assert_eq(RotateLeft(5, 1), 10);
   cr_assert_eq(RotateLeft(5, 2), 20);
   cr_assert_eq(RotateLeft(0x80000000,1), 1);
   cr_assert_eq(RotateLeft(1,31), 2147483648);
   cr_assert_eq(RotateLeft(0,31), 0);
   

   
}

Test(SwapOddEvenBits, examples) {
   cr_assert_eq(SwapOddEvenBits(23), 43);
   cr_assert_eq(SwapOddEvenBits(0),0);
   cr_assert_eq(SwapOddEvenBits(0xFFFFFFFF),-1);
   cr_assert_eq(SwapOddEvenBits(1),2);
   cr_assert_eq(SwapOddEvenBits(0x80000000),-1073741824);


}

/* =========================
* PART 2: IEEE 754 Float
* ========================= */

Test(ConstructFloat, positive_examples) {
   float f = construct_float_sf(0x00, 0x7F, 0x000000);
   cr_assert_float_eq(f, 1.0, 0.000001);

   float f1 = construct_float_sf(0x00, 0x7E, 0x000000);
   cr_assert_float_eq(f1, 0.5, 0.000001);

   float f2 = construct_float_sf(0x00, 0x7F, 0x200000);
   cr_assert_float_eq(f2, 1.25, 0.000001);

   float f3 = construct_float_sf(0x00, 0x00, 0x000000);
   cr_assert_float_eq(f3, 0.0, 0.000001);

   float f4 = construct_float_sf(0x00, 0x7E, 0x000001);
   cr_assert_float_eq(f4, 0.5, 0.000001);

   float f5 = construct_float_sf(0x00, 0x7E, 0x200000);
   cr_assert_float_eq(f5, 0.625, 0.000001);

}

Test(ConstructFloat, negative_examples) {
   float f = construct_float_sf(0x01, 0x7F, 0x200000);
   cr_assert_float_eq(f, -1.25, 0.001);

   float f1 = construct_float_sf(0x01, 0x7F, 0x000000);
   cr_assert_float_eq(f1, -1.0, 0.000001);

   float f2 = construct_float_sf(0x01, 0x7F, 0x200000);
   cr_assert_float_eq(f2, -1.25, 0.000001);

   float f3 = construct_float_sf(0x01, 0x7F, 0x400000);
   cr_assert_float_eq(f3, -1.5, 0.000001);

   float f4 = construct_float_sf(0x01, 0x7E, 0x000000);
   cr_assert_float_eq(f4, -0.5, 0.000001);

   float f5 = construct_float_sf(0x01, 0x7E, 0x200000);
   cr_assert_float_eq(f5, -0.625, 0.000001);
}

/* =========================
* PART 3: Integer Conversion
* ========================= */
/* NOTE:
* We do NOT test output matching here.
* Students are encouraged to visually inspect output.
* TAs will use stronger hidden tests.
*/

Test(ReprConvert, basic_run) {
   repr_convert('2', '2', 0x59f2ca50);
   repr_convert('S', '2', 0x80000000);
   repr_convert('2','S',0);
   repr_convert('2','S',5);
   repr_convert('2','S',-5);
   repr_convert('S','2',5);
   repr_convert('S','2',-5);
   repr_convert('2','S',0x80000000);
   repr_convert('2','2',0x80000000);
   repr_convert('S','S',0x80000000);
   repr_convert('X','S',0x80000000);
   repr_convert('S','4',0x80000000);
}




