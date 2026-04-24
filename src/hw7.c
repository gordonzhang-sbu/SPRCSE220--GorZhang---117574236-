#include "hw7.h"

bst_sf* insert_bst_sf(matrix_sf *mat, bst_sf *root) {
    //If there is not root, create a root
    if (!root){
        bst_sf *node = malloc(sizeof(bst_sf));
        if (!node){
            return NULL;
        }

        node->mat = mat;
        node->left_child = NULL;
        node->right_child = NULL;
        return node;
    }

    //If the name of the given mat is smaller than the root mat name, then mat is the left child, otherwise the right child
    //We called the function recursively so that it goes through the whole subtree of root
    if (mat->name < root->mat->name){
        root->left_child = insert_bst_sf(mat, root->left_child);
    } else {
        root->right_child = insert_bst_sf(mat, root->right_child);
    }

    return root;
}

matrix_sf* find_bst_sf(char name, bst_sf *root) {
    //If not found at all
    if (root == NULL){
        return NULL;
    }

    //If we found the right name mat, return the mat
    if (name == root->mat->name){
        return root->mat;
    }

    //If we did not find the mat, we check the subtree, depending on the value of name
    if (name < root->mat->name){
        return find_bst_sf(name, root->left_child);
    } else {
        return find_bst_sf(name, root->right_child);
    }
}

void free_bst_sf(bst_sf *root) {
    if (root == NULL){
        return;
    }

    //Free left and right subtree
    free_bst_sf(root->left_child);
    free_bst_sf(root->right_child);

    //free the root
    free(root->mat);
    free(root);

}

matrix_sf* add_mats_sf(const matrix_sf *mat1, const matrix_sf *mat2) {
    //If any of the matrix is null just return null
    if ( !mat1 || !mat2){
        return NULL;
    }

    //If the dimension of the matrix does not match up just return null
    if (mat1->num_rows != mat2->num_rows || mat1->num_cols != mat2->num_cols){
        return NULL;
    }

    //Initializing the result matrix
    unsigned int rows = mat1->num_rows;
    unsigned int cols = mat2->num_cols;
    unsigned int totalLength = rows * cols;
    matrix_sf *result = malloc(sizeof(matrix_sf) + totalLength * sizeof(int));
    
    //If nothing is initialize return null
    if (!result){
        return NULL;
    }

    //Pass the augement into the struct
    result->name = 's';
    result->num_rows = rows;
    result->num_cols = cols;

    //Perform addition
    for (unsigned int i=0; i<totalLength; i++){
        result->values[i] = mat1->values[i] + mat2->values[i];
    }

    return result;
}

matrix_sf* mult_mats_sf(const matrix_sf *mat1, const matrix_sf *mat2) {
    //If any of the matrix is null just return null
    if ( !mat1 || !mat2){
        return NULL;
    }

    //If the dimension of the matrix does not match up just return null
    if (mat1->num_cols != mat2->num_rows){
        return NULL;
    }

    //Initializing the result matrix
    unsigned int row = mat1->num_rows;
    unsigned int col = mat2->num_cols;
    matrix_sf *result = malloc(sizeof(matrix_sf) + row * col * sizeof(int));
    
    //If nothing is initialize return null
    if (!result){
        return NULL;
    }

    //Pass the augement into the struct
    result->name = 'p';
    result->num_rows = row;
    result->num_cols = col;

    for (unsigned int i = 0; i < row * col; i++){
        result->values[i] = 0;
    }

    //Loop through the i-th row of mat1
    for (unsigned int i = 0; i < row; i++){
        //Loop through the i-th col of mat2
        for (unsigned int j = 0; j < col; j++){
            int sum = 0;
            //Find the dot product of i-th row of mat1 and i-th col of mat2
            for (unsigned int k = 0; k < mat1->num_cols; k++){
                //a takes the mat1 values horizontally
                int a = mat1 -> values[i * mat1->num_cols + k];
                //b takes the mat2 values vertically
                int b = mat2 -> values[k * col + j];
                sum += a * b;
            }
            //Assign the sum to result
            result->values[i*col+j] = sum;
        }
    }


   return result;
}

matrix_sf* transpose_mat_sf(const matrix_sf *mat) {
    //If the matrix is null just return null
    if ( !mat ){
        return NULL;
    }
    
    //Initialize the result matrix
    unsigned int rows = mat->num_rows;
    unsigned int cols = mat->num_cols;
    matrix_sf *result = malloc(sizeof(matrix_sf) + rows * cols * sizeof(int));

    //If nothing is initialize return null
    if (!result){
        return NULL;
    }

    //Pass the augement into the struct
    result->name = 't';
    //In transpose col becomes row, and row becomes col
    result->num_rows = cols;
    result->num_cols = rows;

    //Perform transposing
    for (unsigned int i = 0; i < rows; i++){
        for (unsigned int j = 0; j < cols; j++){
            //The values in i-th row is the values in i-th col from the original matrix
            result->values[j * rows + i] = mat->values[i * cols + j];
        }
    }

    return result;
}

matrix_sf* create_matrix_sf(char name, const char *expr) {
    unsigned int rows;
    unsigned int cols;

    //Get the first two unsigned int from expr
    sscanf(expr, "%u %u", &rows, &cols);

    //Move the char pointers beyond the rows and cols to find "[" in the expr
    const char *p = strchr(expr, '[');
    p++;

    //Initialize the result matrix
    unsigned int totalLength = rows * cols;
    matrix_sf *result = malloc(sizeof(matrix_sf) + totalLength * sizeof(int));

    //If nothing is initialize return null
    if (!result){
        return NULL;
    }

    //Pass the augement into the struct
    result->name = name;
    result->num_rows = rows;
    result->num_cols = cols;

    //Loop through the numbers inside []
    for (unsigned int i = 0; i < totalLength; i++){
        //If the current char is not a number skip it
        while (*p && !isdigit(*p) && *p != '-'){
            p++;
        }
        sscanf(p,"%d", &result->values[i]);

        //Skip for formatting
        while (*p && *p != ' ' && *p != ';' && *p != ']'){
            p++;
        }
        //Advance the pointer to the next char
        p++;
    }


    return result;
}

//Helper function for infix2postfix_sf
int precedence(char operation){
    //Check for precedence
    if (operation == '\'' ) {
        return 3;
    } else if (operation == '*'){
        return 2;
    } else if (operation == '+'){
        return 1;
    } else {
        return 0;
    }
}

char* infix2postfix_sf(char *infix) {
    //Initialize for result
    char *result = malloc(MAX_LINE_LEN);
    char *stack = malloc(MAX_LINE_LEN);
    int top = -1;
    int resultCounter = 0;

    //Loop through the infix expression
    for (int i = 0; infix[i] ; i++){
        char current = infix[i];

        //skip for spaces
        if (current == ' '){
            continue;
        }

        //If the current char is a number or letter, add then to result
        if (isalnum(current)){
            result[resultCounter++] = current;
        } else if (current == '(') {
            //If the current char is a (, push it to the stack
            stack[++top] = current;
        } else if (current == ')'){
            //pop the stack and move all to result until finding a matching parenthesis
            while(top >= 0 && stack[top] != '('){
                result[resultCounter++] = stack[top--];
            }
            //Remove (
            if (top >= 0 && stack[top] == '('){
                top--;
            }
        } else {
            //Depending on the order of precedence, pop the stack and add it to result
            while (top >= 0 && precedence(stack[top]) >= precedence(current)){
                result[resultCounter++] = stack[top--];
            }
            //Push the current char to stack
            stack[++top] = current;
            }
        }

        //Pop out all the remaining operators into result
        while (top >= 0){
            result[resultCounter++] = stack[top--];
        }

        //Add string terminator
        result[resultCounter] = '\0';
        free(stack);
        return result;
}

matrix_sf* evaluate_expr_sf(char name, char *expr, bst_sf *root) {
    char *postfix = infix2postfix_sf(expr);

    matrix_sf *stack[MAX_LINE_LEN];
    int top = -1;

    //Loop through the the postfix expression
    for (int i = 0; postfix[i] ; i++){
        char current = postfix[i];

        if (current == ' '){
            continue;
        }

        //If the current char is a matrix, then search the matrix in root, and add it to the stack
        if (isalpha(current)){
            matrix_sf *temp = find_bst_sf(current, root);
            if (!temp) {
                free(postfix);
                return NULL;
            }
            stack[++top] = temp;
        } else if (current == '\''){
            if (top < 0){
                free(postfix);
                return NULL;
            }

            //If we need to do the transpose, pop the matrix and transpose it
            matrix_sf *temp = stack[top--];
            matrix_sf *transpose = transpose_mat_sf(temp);

            if (!transpose){
                free(postfix);
                return NULL;
            }

            stack[++top] = transpose;

        } else if (current == '*'){
            if (top < 1){
                free(postfix);
                return NULL;
            }
            //If it is multiplication, pop two matrix and times them
            matrix_sf *temp1 = stack[top--];
            matrix_sf *temp2 = stack[top--];

            matrix_sf *product = mult_mats_sf(temp2, temp1);

            if (!product){
                free(postfix);
                return NULL;
            }

            stack[++top] = product;

        } else if (current == '+'){
            if (top < 1){
                free(postfix);
                return NULL;
            }
            //If it is addition, pop two matrix and add them
            matrix_sf *temp1 = stack[top--];
            matrix_sf *temp2 = stack[top--];

            matrix_sf *sum = add_mats_sf(temp2, temp1);

            if (!sum){
                free(postfix);
                return NULL;
            }

            stack[++top] = sum;
        }

    }

    //The final result will be whatever is left in the stack
    matrix_sf *result = stack[top];
    result->name = name;
    //Free the space postfix allocates
    free(postfix);
    return result;
}

matrix_sf *execute_script_sf(char *filename) {
    FILE *file = fopen(filename, "r");
    //If we cannot open the file, just return null
    if (!file) {
        return NULL;
    }
    
    char *line = NULL;
    size_t length =MAX_LINE_LEN;

    bst_sf *root = NULL;
    matrix_sf *result = NULL;

    //Read the file line by line
    while(getline(&line, &length, file) != -1 ){
        //Skips the empty line
        if (strlen(line) == 0 || line[0] == '\n'){
            continue;
        }

        char name;
        char *expr;

        //If the current line is for matrix definition
        if(strchr(line, '[') != NULL){
            //Get the matrix definition
            //Get name
            sscanf(line, " %c =", &name);
            //Get the definition
            expr = strchr(line, '=') + 1;

            //create the matrix
            matrix_sf *mat = create_matrix_sf(name, expr);

            //Insert the result into the tree
            root = insert_bst_sf(mat, root);
            result = mat;
        } else {
            //Get the matrix name
            sscanf (line, " %c =", &name);
            //Get expression
            expr = strchr(line, '=') + 1;

            //Insert the result into the tree
            matrix_sf *mat = evaluate_expr_sf(name, expr, root);
            root = insert_bst_sf(mat, root);
            result = mat;
        }

    }

    //Free and close unused memory
    free(line);
    fclose(file);
    free_bst_sf(root);
    
    return result;
}

// This is a utility function used during testing. Feel free to adapt the code to implement some of
// the assignment. Feel equally free to ignore it.
matrix_sf *copy_matrix(unsigned int num_rows, unsigned int num_cols, int values[]) {
    matrix_sf *m = malloc(sizeof(matrix_sf)+num_rows*num_cols*sizeof(int));
    m->name = '?';
    m->num_rows = num_rows;
    m->num_cols = num_cols;
    memcpy(m->values, values, num_rows*num_cols*sizeof(int));
    return m;
}

// Don't touch this function. It's used by the testing framework.
// It's been left here in case it helps you debug and test your code.
void print_matrix_sf(matrix_sf *mat) {
    assert(mat != NULL);
    assert(mat->num_rows <= 1000);
    assert(mat->num_cols <= 1000);
    printf("%d %d ", mat->num_rows, mat->num_cols);
    for (unsigned int i = 0; i < mat->num_rows*mat->num_cols; i++) {
        printf("%d", mat->values[i]);
        if (i < mat->num_rows*mat->num_cols-1)
            printf(" ");
    }
    printf("\n");
}
