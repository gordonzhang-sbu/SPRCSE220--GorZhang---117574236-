#include "unit_tests.h"
#include "hw6.h"


static char args[ARGS_TEXT_LEN];


// //Testing part 1
Test(Part1, missingArgument) {
    char *temp = "missignArgument";
    sprintf(args, "-s -r O %s/%s.in.txt %s/%s.out.txt", TEST_INPUT_DIR, temp, TEST_OUTPUT_DIR, temp);
    int status = run_using_system_no_valgrind(temp, args);
    expect_error_exit(status, MISSING_ARGUMENT);
}
Test(Part1, duplicated) {
    char *temp = "duplicated";
    prep_files("basic.in.txt", temp);    
    sprintf(args, "-r this -r is -r -r -r -r -r %s/%s.in.txt %s/%s.out.txt", TEST_INPUT_DIR, temp, TEST_OUTPUT_DIR, temp);
    int status = run_using_system_no_valgrind(temp, args);
    expect_error_exit(status, DUPLICATE_ARGUMENT);
}
Test(Part1, inputMissing) {
    char *temp = "inputMissing";
    sprintf(args, "-s very -r hard /%s.in.txt %s/%s.out.txt", temp, TEST_OUTPUT_DIR, temp);
    int status = run_using_system_no_valgrind(temp, args);
    expect_error_exit(status, INPUT_FILE_MISSING);
}
Test(Part1, outputUnwritable) {
    char *temp = "outputUnwritable"; 
    prep_files("basic.in.txt", temp);    
    sprintf(args, "-s the -r Zhang %s/%s.in.txt /%s.out.txt", TEST_INPUT_DIR, temp, temp);
    int status = run_using_system_no_valgrind(temp, args);
    expect_error_exit(status, OUTPUT_FILE_UNWRITABLE);
}
Test(Part1, sArgumentMissing) {
    char *temp = "sArgumentMissing";
    prep_files("basic.in.txt", temp);    
    sprintf(args, "-s -w -s Gordon -r Zhang %s/%s.in.txt %s/%s.out.txt", TEST_INPUT_DIR, temp, TEST_OUTPUT_DIR, temp);
    int status = run_using_system_no_valgrind(temp, args);
    expect_error_exit(status, S_ARGUMENT_MISSING);
}
Test(Part1, rArgumentMissing) {
    char *temp = "rArgumentMissing";
    prep_files("basic.in.txt", temp);    
    sprintf(args, "-s he -r -r Gordon -g Zhang -l 13,4 %s/%s.in.txt %s/%s.out.txt", TEST_INPUT_DIR, temp, TEST_OUTPUT_DIR, temp);
    int status = run_using_system_no_valgrind(temp, args);
    expect_error_exit(status, R_ARGUMENT_MISSING);
}
Test(Part1, lArgumentMissing) {
    char *temp = "lArgumentMissing";
    prep_files("basic.in.txt", temp);    
    sprintf(args, "-s M -r Zhang -l -9,-8 %s/%s.in.txt %s/%s.out.txt", TEST_INPUT_DIR, temp, TEST_OUTPUT_DIR, temp);
    int status = run_using_system_no_valgrind(temp, args);
    expect_error_exit(status, L_ARGUMENT_INVALID);
}
Test(Part1, invalidW) {
    char *temp = "invalidW";
    prep_files("basic.in.txt", temp);    
    sprintf(args, "-s *hi* -r hi -w %s/%s.in.txt %s/%s.out.txt", TEST_INPUT_DIR, temp, TEST_OUTPUT_DIR, temp);
    int status = run_using_system_no_valgrind(temp, args);
    expect_error_exit(status, WILDCARD_INVALID);
}
Test(Part1, successful) {
    char *temp = "successful";
    prep_files("basic.in.txt", temp);    
    sprintf(args, "-s This -r Works -l 1,2 %s/%s.in.txt %s/%s.out.txt", TEST_INPUT_DIR, temp, TEST_OUTPUT_DIR, temp);
    int status = run_using_system_no_valgrind(temp, args);
    expect_error_exit(status, 0);
}

// //Part 2
Test(Part2, wordInsideWord){
    char *temp = "normalPart2";
    prep_files("normalPart2.txt", temp);    
    sprintf(args, "-s aa -r b -l 1,2 %s/%s.in.txt %s/%s.out.txt", TEST_INPUT_DIR, temp, TEST_OUTPUT_DIR, temp);
    int status = run_using_system_no_valgrind(temp, args);
    expect_error_exit(status, 0);
}
Test(Part2, substring){
    char *temp = "substringPart2";
    prep_files("substringPart2.txt", temp);    
    sprintf(args, "-s the -r eht -l 1,2 %s/%s.in.txt %s/%s.out.txt", TEST_INPUT_DIR, temp, TEST_OUTPUT_DIR, temp);
    int status = run_using_system_no_valgrind(temp, args);
    expect_error_exit(status, 0);
}
Test(Part2, noMatch){
    char *temp = "noMatch";
    prep_files("noMatch.txt", temp);    
    sprintf(args, "-s the -r eht -l 1,2 %s/%s.in.txt %s/%s.out.txt", TEST_INPUT_DIR, temp, TEST_OUTPUT_DIR, temp);
    int status = run_using_system_no_valgrind(temp, args);
    expect_error_exit(status, 0);
}
Test(Part2, sSmaller){
    char *temp = "aSmaller";
    prep_files("aSmaller.txt", temp);    
    sprintf(args, "-s a -r apple -l 1,2 %s/%s.in.txt %s/%s.out.txt", TEST_INPUT_DIR, temp, TEST_OUTPUT_DIR, temp);
    int status = run_using_system_no_valgrind(temp, args);
    expect_error_exit(status, 0);
}
Test(Part2, rSmaller){
    char *temp = "rSmaller";
    prep_files("rSmaller.txt", temp);    
    sprintf(args, "-s Gordon -r G -l 1,2 %s/%s.in.txt %s/%s.out.txt", TEST_INPUT_DIR, temp, TEST_OUTPUT_DIR, temp);
    int status = run_using_system_no_valgrind(temp, args);
    expect_error_exit(status, 0);
}
Test(Part2, withLine){
    char *temp = "withLine";
    prep_files("withLine.txt", temp);    
    sprintf(args, "-s Hello -r hi -l 1,2 %s/%s.in.txt %s/%s.out.txt", TEST_INPUT_DIR, temp, TEST_OUTPUT_DIR, temp);
    int status = run_using_system_no_valgrind(temp, args);
    expect_error_exit(status, 0);
}

//Part 3
Test(Part3, prefix){
    char *temp = "prefixPart3";
    prep_files("prefixPart3.txt", temp);    
    sprintf(args, "-s Stony* -r X -w -l 1,100 %s/%s.in.txt %s/%s.out.txt", TEST_INPUT_DIR, temp, TEST_OUTPUT_DIR, temp);
    int status = run_using_system_no_valgrind(temp, args);
    expect_error_exit(status, 0);
}
Test(Part3, suffix){
    char *temp = "suffixPart3";
    prep_files("suffixPart3.txt", temp);    
    sprintf(args, "-s *ny -r X -w -l 1,100 %s/%s.in.txt %s/%s.out.txt", TEST_INPUT_DIR, temp, TEST_OUTPUT_DIR, temp);
    int status = run_using_system_no_valgrind(temp, args);
    expect_error_exit(status, 0);
}
Test(Part3, consecutivePuntuation){
    char *temp = "consecutivePuntuationPart3";
    prep_files("consecutivePuntuationPart3.txt", temp);    
    sprintf(args, "-s the* -r X -w -l 1,100 %s/%s.in.txt %s/%s.out.txt", TEST_INPUT_DIR, temp, TEST_OUTPUT_DIR, temp);
    int status = run_using_system_no_valgrind(temp, args);
    expect_error_exit(status, 0);
}
Test(Part3, mixedTogether){
    char *temp = "mixedTogetherPart3";
    prep_files("mixedTogetherPart3.txt", temp);    
    sprintf(args, "-s the* -r X -w -l 1,100 %s/%s.in.txt %s/%s.out.txt", TEST_INPUT_DIR, temp, TEST_OUTPUT_DIR, temp);
    int status = run_using_system_no_valgrind(temp, args);
    expect_error_exit(status, 0);
}