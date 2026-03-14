#include <criterion/criterion.h>
#include "../cse_caesar.h"

//encryptCaesar test
Test(encryptCaesar, basic) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    int r = encryptCaesar("Gordon", buf, 2);
    cr_expect_eq(r, 6);
    cr_expect_str_eq(buf, "Irviuu__EOM__");
}
Test(encryptCaesar, plaintextNull) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    int r = encryptCaesar(NULL, buf, 2);
    cr_expect_eq(r, -2);
    cr_expect_str_eq(buf, "xxxxxxxxxxxxxxxxxxxxxxxx");
}
Test(encryptCaesar, cipherNull) {
    char buf[32];
    int r = encryptCaesar("Gordon", NULL, 2);
    cr_expect_eq(r, -2);
    cr_expect_str_eq(buf, "");
}
Test(encryptCaesar, noRoom) {
    char buf[1] = "x";
    int r = encryptCaesar("Gordon", buf, 2);
    cr_expect_eq(r, -1);
    cr_expect_str_eq(buf, "x");
}
Test(encryptCaesar, onlyNum) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    int r = encryptCaesar("12345", buf, 2);
    cr_expect_eq(r, 5);
    cr_expect_str_eq(buf, "36925__EOM__");
}
Test(encryptCaesar, onlySpecialChar) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    int r = encryptCaesar(";.];.].][';/].;", buf, 2);
    cr_expect_eq(r, 0);
    cr_expect_str_eq(buf, ";.];.].][';/].;__EOM__");
}
Test(encryptCaesar, mixNumAndSpecialChar) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    int r = encryptCaesar("a,a,a,a,a,a,a,a", buf, 2);
    cr_expect_eq(r, 8);
    cr_expect_str_eq(buf, "c,e,g,i,k,m,o,q__EOM__");
}
Test(encryptCaesar, mixAll) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    int r = encryptCaesar("a;g.' sg.3;w'r.;", buf, 2);
    cr_expect_eq(r, 7);
    cr_expect_str_eq(buf, "c;k.' ap.3;j'g.;__EOM__");
}
Test(encryptCaesar, empty) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    int r = encryptCaesar("", buf, 2);
    cr_expect_eq(r, 0);
    cr_expect_str_eq(buf, "__EOM__");
}
Test(encryptCaesar, negative) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    int r = encryptCaesar("Gordon", buf, -2);
    cr_expect_eq(r, 6);
    cr_expect_str_eq(buf, "Enreqq__EOM__");
}




//decryptCaesar test
Test(decryptCaesar, basic) {
    char buf[32] = "xxxxxxxx";
    int r = decryptCaesar("Irviuu__EOM__", buf, 2);
    cr_expect_eq(r, 6);
    cr_expect_str_eq(buf, "Gordon");
}
Test(decryptCaesar, plaintextNull) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    int r = decryptCaesar(NULL, buf, 2);
    cr_expect_eq(r, -2);
    cr_expect_str_eq(buf, "xxxxxxxxxxxxxxxxxxxxxxxx");
}
Test(decryptCaesar, cipherNull) {
    char buf[32];
    int r = decryptCaesar("Gordon__EOM__", NULL, 2);
    cr_expect_eq(r, -2);
    cr_expect_str_eq(buf, "");
}
Test(decryptCaesar, noMarker) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    int r = decryptCaesar("Gordon", buf, 2);
    cr_expect_eq(r, -1);
    cr_expect_str_eq(buf, "xxxxxxxxxxxxxxxxxxxxxxxx");
}
Test(decryptCaesar, onlyNum) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    int r = decryptCaesar("36925__EOM__", buf, 2);
    cr_expect_eq(r, 5);
    cr_expect_str_eq(buf, "12345");
}
Test(decryptCaesar, onlySpecialChar) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    int r = decryptCaesar(";.];.].][';/].;__EOM__", buf, 2);
    cr_expect_eq(r, 0);
    cr_expect_str_eq(buf, ";.];.].][';/].;");
}
Test(decryptCaesar, mixNumAndSpecialChar) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    int r = decryptCaesar("c,e,g,i,k,m,o,q__EOM__", buf, 2);
    cr_expect_eq(r, 8);
    cr_expect_str_eq(buf, "a,a,a,a,a,a,a,a");
}
Test(decryptCaesar, mixAll) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    int r = decryptCaesar("c;k.' ap.3;j'g.;__EOM__", buf, 2);
    cr_expect_eq(r, 7);
    cr_expect_str_eq(buf, "a;g.' sg.3;w'r.;");
}
Test(decryptCaesar, empty) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    int r = decryptCaesar("__EOM__", buf, 2);
    cr_expect_eq(r, 0);
    cr_expect_str_eq(buf, "");
}
Test(decryptCaesar, negative) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    int r = decryptCaesar("Enreqq__EOM__", buf, -2);
    cr_expect_eq(r, 6);
    cr_expect_str_eq(buf, "Gordon");
}


