/*
Name: Gordon Zhang
SBU ID: 117574236
*/

#include "unit_tests.h"
#include "hw7.h"

TestSuite(student_tests, .timeout=TEST_TIMEOUT); 
//Addition test
Test(student_tests, add1) {
    run_script_with_valgrind("tests.in/additionTest01.txt");
    expect_outfile_matches("additionTest01");
}
// Test(student_tests, add2) {
//     run_script_with_valgrind("tests.in/additionTest02.txt");
//     expect_outfile_matches("additionTest02");
// }
// Test(student_tests, add3) {
//     run_script_with_valgrind("tests.in/additionTest03.txt");
//     expect_outfile_matches("additionTest03");
// }
// Test(student_tests, add4) {
//     run_script_with_valgrind("tests.in/additionTest04.txt");
//     expect_outfile_matches("additionTest04");
// }
// Test(student_tests, add5) {
//     run_script_with_valgrind("tests.in/additionTest05.txt");
//     expect_outfile_matches("additionTest05");
// }
