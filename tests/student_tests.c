/*
Name: Gordon Zhang
SBU ID: 117574236
*/

#include "unit_tests.h"
#include "hw7.h"

TestSuite(student_tests, .timeout=TEST_TIMEOUT); 
//Addition test
Test(student_tests, addBasic) {
    run_script_without_valgrind("additionTest01");
    expect_outfile_matches("additionTest01");
}
Test(student_tests, addSmallMatrix) {
    run_script_without_valgrind("additionTest02");
    expect_outfile_matches("additionTest02");
}
Test(student_tests, addNegative) {
    run_script_without_valgrind("additionTest03");
    expect_outfile_matches("additionTest03");
}
Test(student_tests, addRectangular) {
    run_script_without_valgrind("additionTest04");
    expect_outfile_matches("additionTest04");
}
Test(student_tests, addWithItself) {
    run_script_without_valgrind("additionTest05");
    expect_outfile_matches("additionTest05");
}

//Multiplication test
Test(student_tests, multiplicationBasic) {
    run_script_without_valgrind("multiplicationTest01");
    expect_outfile_matches("multiplicationTest01");
}
Test(student_tests, multiplicationRectangular) {
    run_script_without_valgrind("multiplicationTest02");
    expect_outfile_matches("multiplicationTest02");
}
Test(student_tests, multiplicationItself) {
    run_script_without_valgrind("multiplicationTest03");
    expect_outfile_matches("multiplicationTest03");
}
Test(student_tests, multiplicationZeros) {
    run_script_without_valgrind("multiplicationTest04");
    expect_outfile_matches("multiplicationTest04");
}
Test(student_tests, multiplicationIdentityMatrix) {
    run_script_without_valgrind("multiplicationTest05");
    expect_outfile_matches("multiplicationTest05");
}

//Transpose test
Test(student_tests, transposeBasic) {
    run_script_without_valgrind("transposeTest01");
    expect_outfile_matches("transposeTest01");
}
Test(student_tests, transposeOneRow) {
    run_script_without_valgrind("transposeTest02");
    expect_outfile_matches("transposeTest02");
}
Test(student_tests, transposeOneCol) {
    run_script_without_valgrind("transposeTest03");
    expect_outfile_matches("transposeTest03");
}
Test(student_tests, transposeOneByOne) {
    run_script_without_valgrind("transposeTest04");
    expect_outfile_matches("transposeTest04");
}
Test(student_tests, transposeDoubleTranspose) {
    run_script_without_valgrind("transposeTest05");
    expect_outfile_matches("transposeTest05");
}

//create_matrix_sf test
Test(student_tests, create_matrix_sfBasic) {
    run_script_without_valgrind("create_matrix_sfTest01");
    expect_outfile_matches("create_matrix_sfTest01");
}
Test(student_tests, create_matrix_sfBigSpace) {
    run_script_without_valgrind("create_matrix_sfTest02");
    expect_outfile_matches("create_matrix_sfTest02");
}
Test(student_tests, create_matrix_sfOnlyOne) {
    run_script_without_valgrind("create_matrix_sfTest03");
    expect_outfile_matches("create_matrix_sfTest03");
}
Test(student_tests, create_matrix_sfNegative) {
    run_script_without_valgrind("create_matrix_sfTest04");
    expect_outfile_matches("create_matrix_sfTest04");
}
Test(student_tests, create_matrix_sfMix) {
    run_script_without_valgrind("create_matrix_sfTest05");
    expect_outfile_matches("create_matrix_sfTest05");
}

//Infix to postfix test
Test(student_tests, infix2postfixBasic) {
    run_script_without_valgrind("infix2postfixTest01");
    expect_outfile_matches("infix2postfixTest01");
}
Test(student_tests, infix2postfixPrecedence) {
    run_script_without_valgrind("infix2postfixTest02");
    expect_outfile_matches("infix2postfixTest02");
}
Test(student_tests, infix2postfixParentheses) {
    run_script_without_valgrind("infix2postfixTest03");
    expect_outfile_matches("infix2postfixTest03");
}
Test(student_tests, infix2postfixTranspose) {
    run_script_without_valgrind("infix2postfixTest04");
    expect_outfile_matches("infix2postfixTest04");
}
Test(student_tests, infix2postfixItself) {
    run_script_without_valgrind("infix2postfixTest05");
    expect_outfile_matches("infix2postfixTest05");
}