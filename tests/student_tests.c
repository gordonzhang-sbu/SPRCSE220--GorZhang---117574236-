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