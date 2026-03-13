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
    cr_expect_eq(strgLen("LENGTH"), -1);
}

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
