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
Test(strgCopy, basic) {
    char d[20];
    strgCopy("I like C", d, 20);
    cr_expect_str_eq(d, "I like C");
}
Test(strgCopy, exactSize) {
    char d[6];
    strgCopy("Happy", d, 6);
    cr_expect_str_eq(d, "Happy");
}
Test(strgCopy, notEnough) {
    char d[6];
    strgCopy("Happy Learning", d, 6);
    cr_expect_str_eq(d, "Happy");
}
Test(strgCopy, onlyOne) {
    char d[1];
    strgCopy("Happy Learning", d, 1);
    cr_expect_str_eq(d, "");
}
Test(strgCopy, sizeZero) {
    char d[1] = {'\0'};
    strgCopy("Happy Learning", d, 0);
    cr_expect_str_eq(d, "");
}
Test(strgCopy, nullS) {
    char d[6] = "";
    strgCopy(NULL, d, 6);
    cr_expect_str_eq(d, "");
}
Test(strgCopy, nullD) {
    char d[1]={'\0'};
    strgCopy("Happy Learning", d, 1);
    cr_expect_str_eq(d , "");
}
Test(strgCopy, emptyS) {
    char d[6];
    strgCopy("", d, 6);
    cr_expect_str_eq(d, "");
}
Test(strgCopy, exactlyOneLess) {
    char d[5];
    strgCopy("Happy", d, 5);
    cr_expect_str_eq(d, "Happ");
}
Test(strgCopy, bothNull) {
    char d[6] = {'\0'};
    strgCopy(NULL, d, 6);
    cr_expect_str_eq(d, "");
}


//strgChangeCase test
Test(strgChangeCase, lowToUp) {
    char s[] = "gordon";
    strgChangeCase(s);
    cr_expect_str_eq(s, "GORDON");
}
Test(strgChangeCase, upToLow) {
    char s[] = "GORDON";
    strgChangeCase(s);
    cr_expect_str_eq(s, "gordon");
}
Test(strgChangeCase, onlyNum) {
    char s[] = "123456789";
    strgChangeCase(s);
    cr_expect_str_eq(s, "123456789");
}
Test(strgChangeCase, onlySpecialChar) {
    char s[] = ".;';;'.';.";
    strgChangeCase(s);
    cr_expect_str_eq(s, ".;';;'.';.");
}
Test(strgChangeCase, mixSpecialChar) {
    char s[] = "G,o,r,d,o,n";
    strgChangeCase(s);
    cr_expect_str_eq(s, "g,O,R,D,O,N");
}
Test(strgChangeCase, mixNumAndSpecialChar) {
    char s[] = "1,1,1,1,1,1,1";
    strgChangeCase(s);
    cr_expect_str_eq(s, "1,1,1,1,1,1,1");
}
Test(strgChangeCase, mixWithNewLine) {
    char s[] = "a\na\na\na";
    strgChangeCase(s);
    cr_expect_str_eq(s, "A\nA\nA\nA");
}
Test(strgChangeCase, alternate) {
    char s[] = "aAaAaAaAa";
    strgChangeCase(s);
    cr_expect_str_eq(s, "AaAaAaAaA");
}
Test(strgChangeCase, withNum) {
    char s[] = "a1aaaaaa1a";
    strgChangeCase(s);
    cr_expect_str_eq(s, "a1aAAAAa1a");
}
Test(strgChangeCase, alternateWithNum) {
    char s[] = "a1a1a1a1a1a";
    strgChangeCase(s);
    cr_expect_str_eq(s, "a1a1a1a1a1a");
}
Test(strgChangeCase, empty) {
    char s[] = "";
    strgChangeCase(s);
    cr_expect_str_eq(s, "");
}
Test(strgChangeCase, null) {
    char s[] = {'\0'};
    strgChangeCase(s);
    cr_expect_str_eq(s, "");
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
