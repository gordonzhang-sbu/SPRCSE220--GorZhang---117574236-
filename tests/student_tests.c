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
Test(student_tests,infix2postfix_sfBasic) {
    char *actual = infix2postfix_sf("A+B");
    char *expected = "AB+";
    cr_expect_arr_eq(actual, expected, strlen(expected),
        "The returned postfix expression was %s, but it should have been %s",
        actual, expected);
}
Test(student_tests,infix2postfix_sfPrecedence) {
    char *actual = infix2postfix_sf("A+B*C");
    char *expected = "ABC*+";
    cr_expect_arr_eq(actual, expected, strlen(expected),
        "The returned postfix expression was %s, but it should have been %s",
        actual, expected);
}
Test(student_tests,infix2postfix_sfParenthesis) {
    char *actual = infix2postfix_sf("(A+B)*C");
    char *expected = "AB+C*";
    cr_expect_arr_eq(actual, expected, strlen(expected),
        "The returned postfix expression was %s, but it should have been %s",
        actual, expected);
}
Test(student_tests,infix2postfix_sfJustTranspose) {
    char *actual = infix2postfix_sf("A'");
    char *expected = "A'";
    cr_expect_arr_eq(actual, expected, strlen(expected),
        "The returned postfix expression was %s, but it should have been %s",
        actual, expected);
}
Test(student_tests,infix2postfix_sfItself) {


    char *actual = infix2postfix_sf("A");
    char *expected = "A";
    cr_expect_arr_eq(actual, expected, strlen(expected),
        "The returned postfix expression was %s, but it should have been %s",
        actual, expected);
}

//insert_bst_sf and free_bst test
Test(student_tests, insert_bst_sfBasic) {
    matrix_sf *m1 = malloc(sizeof(matrix_sf));
    m1->name = 'B';
    matrix_sf *m2 = malloc(sizeof(matrix_sf));
    m2->name = 'A';
    bst_sf *root = NULL;
    root = insert_bst_sf(m1, root);
    root = insert_bst_sf(m2, root);
    cr_assert_eq(root->mat->name, 'B');
    cr_assert_not_null(root->left_child);
    cr_assert_eq(root->left_child->mat->name, 'A');
    free_bst_sf(root);
}
Test(student_tests, insert_bst_sfRootNull) {
    matrix_sf *m = malloc(sizeof(matrix_sf));
    m->name = 'A';
    bst_sf *root = insert_bst_sf(m, NULL);
    cr_assert_not_null(root);
    cr_assert_eq(root->mat->name, 'A');
    cr_assert_null(root->left_child);
    cr_assert_null(root->right_child);
    free(root->mat);
    free(root);
}
Test(student_tests, insert_bst_sfLeftChild) {
    matrix_sf *m1 = malloc(sizeof(matrix_sf));
    m1->name = 'B';
    matrix_sf *m2 = malloc(sizeof(matrix_sf));
    m2->name = 'A';
    bst_sf *root = NULL;
    root = insert_bst_sf(m1, root);
    root = insert_bst_sf(m2, root);
    cr_assert_eq(root->mat->name, 'B');
    cr_assert_not_null(root->left_child);
    cr_assert_eq(root->left_child->mat->name, 'A');
    free_bst_sf(root);
}
Test(student_tests, insert_bst_sfRightChild) {
    matrix_sf *m1 = malloc(sizeof(matrix_sf));
    m1->name = 'A';
    matrix_sf *m2 = malloc(sizeof(matrix_sf));
    m2->name = 'C';
    bst_sf *root = NULL;
    root = insert_bst_sf(m1, root);
    root = insert_bst_sf(m2, root);
    cr_assert_eq(root->mat->name, 'A');
    cr_assert_not_null(root->right_child);
    cr_assert_eq(root->right_child->mat->name, 'C');
    free_bst_sf(root);
}
Test(student_tests, insert_bst_sfDuplicate) {

    matrix_sf *m1 = malloc(sizeof(matrix_sf));
    m1->name = 'A';
    matrix_sf *m2 = malloc(sizeof(matrix_sf));
    m2->name = 'A';
    bst_sf *root = NULL;
    root = insert_bst_sf(m1, root);
    root = insert_bst_sf(m2, root);
    cr_assert_eq(root->mat->name, 'A');
    cr_assert_not_null(root->right_child);
    cr_assert_eq(root->right_child->mat->name, 'A');
    free_bst_sf(root);
}

//find_bst_sf tests
Test(student_tests, find_bst_sf_rootBasic) {
    matrix_sf *m = malloc(sizeof(matrix_sf));
    m->name = 'A';
    bst_sf *root = insert_bst_sf(m, NULL);
    matrix_sf *found = find_bst_sf('A', root);
    cr_assert_not_null(found);
    cr_assert_eq(found->name, 'A');
    free_bst_sf(root);
}
Test(student_tests, find_bst_sfLeftChild) {
    matrix_sf *m1 = malloc(sizeof(matrix_sf));
    m1->name = 'B';
    matrix_sf *m2 = malloc(sizeof(matrix_sf));
    m2->name = 'A';
    bst_sf *root = NULL;
    root = insert_bst_sf(m1, root);
    root = insert_bst_sf(m2, root);
    matrix_sf *found = find_bst_sf('A', root);
    cr_assert_not_null(found);
    cr_assert_eq(found->name, 'A');
    free_bst_sf(root);
}
Test(student_tests, find_bst_sfRightChild) {
    matrix_sf *m1 = malloc(sizeof(matrix_sf));
    m1->name = 'A';
    matrix_sf *m2 = malloc(sizeof(matrix_sf));
    m2->name = 'C';
    bst_sf *root = NULL;
    root = insert_bst_sf(m1, root);
    root = insert_bst_sf(m2, root);
    matrix_sf *found = find_bst_sf('C', root);
    cr_assert_not_null(found);
    cr_assert_eq(found->name, 'C');
    free_bst_sf(root);
}
Test(student_tests, find_bst_sfNotFound) {
    matrix_sf *m1 = malloc(sizeof(matrix_sf));
    m1->name = 'A';
    matrix_sf *m2 = malloc(sizeof(matrix_sf));
    m2->name = 'B';
    bst_sf *root = NULL;
    root = insert_bst_sf(m1, root);
    root = insert_bst_sf(m2, root);
    matrix_sf *found = find_bst_sf('Z', root);
    cr_assert_null(found);
    free_bst_sf(root);
}
Test(student_tests, find_bst_sfEmpty) {
    matrix_sf *found = find_bst_sf('A', NULL);
    cr_assert_null(found);
}

//evaluate_expr_sf tests
Test(student_tests, evaluate_expr_sfBasic) {
    bst_sf* root = build_bst();
    matrix_sf* result = evaluate_expr_sf('R', "G * C + F'", root);
    expect_matrices_equal(result, 7, 4, (int[]){4597, -1765, 206, -5401, -512, 159, -15, 647, -5547, 2117, -104, 6407, 1720, -523, 199, -1962, 12587, -4696, 281, -14286, 8973, -3330, 436, -9965, 3439, -1138, 222, -3721});
}
Test(student_tests, evaluate_expr_sfOrderChanged) {
    bst_sf* root = build_bst();
    matrix_sf* result = evaluate_expr_sf('R', "F' + G * C", root);
    expect_matrices_equal(result, 7, 4, (int[]){4597, -1765, 206, -5401, -512, 159, -15, 647, -5547, 2117, -104, 6407, 1720, -523, 199, -1962, 12587, -4696, 281, -14286, 8973, -3330, 436, -9965, 3439, -1138, 222, -3721});
}
Test(student_tests, evaluate_expr_sfJustOne) {
    bst_sf* root = build_bst();
    matrix_sf* result = evaluate_expr_sf('R', "F", root);
    expect_matrices_equal(result, 4, 7, (int[]){-77, -20, 111, -2, 41, 117, 118, 21, -29, -45, 135, 98, 54, 131, 54, 1, 80, 143, -127, 148, 114, -81, 87, -33, -2, -6, 115, 59});
}
Test(student_tests, evaluate_expr_sfAddition) {
    bst_sf* root = build_bst();
    matrix_sf* result = evaluate_expr_sf('R', "A + B", root);
    expect_matrices_equal(result, 3, 5, (int[]){6, 27, 4, -26, 32, 30, 39, 20, 93, -47, -88, 24, 21, 16, -18});
}


//execute_script_sf tests
Test(student_tests, add_mats01) { run_script_without_valgrind("execute_script_sfTest01"); }
Test(student_tests, add_mats02) { expect_no_valgrind_errors(run_script_with_valgrind("execute_script_sfTest01")); }
Test(student_tests, multiply01) { run_script_without_valgrind("execute_script_sfTest02"); }
Test(student_tests, multiply02) { expect_no_valgrind_errors(run_script_with_valgrind("execute_script_sfTest02")); }
Test(student_tests, transpose01) { run_script_without_valgrind("execute_script_sfTest03"); }
Test(student_tests, transpose02) { expect_no_valgrind_errors(run_script_with_valgrind("execute_script_sfTest03")); }
Test(student_tests, mix01) { run_script_without_valgrind("execute_script_sfTest04"); }
Test(student_tests, mix02) { expect_no_valgrind_errors(run_script_with_valgrind("execute_script_sfTest04")); }
Test(student_tests, mix03) { run_script_without_valgrind("execute_script_sfTest05"); }
Test(student_tests, mix04) { expect_no_valgrind_errors(run_script_with_valgrind("execute_script_sfTest05")); }