#include <criterion/criterion.h>
#include "../strgPtr.h"

//strgLen Test
Test(strgLen, basic) {
    cr_expect_eq(strgLen("Happy"), 5);
}
Test(strgLen, null) {
    cr_expect_eq(strgLen(NULL), -1);
}
Test(strgLen, nullChar) {
    cr_expect_eq(strgLen('\0'), -1);
}
Test(strgLen, allCap) {
    cr_expect_eq(strgLen("LENGTH"), 6);
}
Test(strgLen, allLow) {
    cr_expect_eq(strgLen("length"), 6);
}
Test(strgLen, mixCapLow) {
    cr_expect_eq(strgLen("LeNgTh"), 6);
}
Test(strgLen, newLine) {
    cr_expect_eq(strgLen("\n"), 1);
}
Test(strgLen, specialChar) {
    cr_expect_eq(strgLen(".[,]/?"), 6);
}
Test(strgLen, space) {
    cr_expect_eq(strgLen(" "), 1);
}
Test(strgLen, number) {
    cr_expect_eq(strgLen("123924167431746172361824781372"), 30);
}
Test(strgLen, mixCharNumSpecial) {
    cr_expect_eq(strgLen("This is CSE 220, I like C programming. :)"), 41);
}
Test(strgLen, empty) {
    cr_expect_eq(strgLen(""), 0);
}





//strgCopy tests
Test(strgCopy, truncation) {
    char d[5];
    strgCopy("Computer Science", d, 5);
    cr_expect_str_eq(d, "Comp");
}










Test(strgChangeCase, adjacency) {
    char s[] = "Stony Brook";
    strgChangeCase(s);
    cr_expect_str_eq(s, "sTONY bROOK");
}

Test(strgDiff, different) {
    char s1[] = "Stony Brook";
    cr_expect_eq(strgDiff(s1, NULL), -2);
}

Test(strgInterleave, priority) {
    char d[6];
    strgInterleave("abcdef", "12", d, 6);
    cr_expect_str_eq(d, "a1b2c");
}

Test(strgReverseLetters, reverse) {
    char d[] = "abc";
    strgReverseLetters(d);
    cr_expect_str_eq(d, "cba");
}
