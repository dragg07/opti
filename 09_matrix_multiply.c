#include <stdio.h>

#define MAX_ROWS 10 // Maximum number of rows for matrices
#define MAX_COLS 10 // Maximum number of columns for matrices

void inputMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void multiplyMatrices(int result[MAX_ROWS][MAX_COLS], int matrix1[MAX_ROWS][MAX_COLS], int matrix2[MAX_ROWS][MAX_COLS], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    printf("Resultant matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    // Get dimensions of matrices
    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    // Check for compatible dimensions
    if (cols1 != rows2) {
        printf("Error: Matrices cannot be multiplied.\n");
        return 1;
    }

    // Declare matrices
    int matrix1[MAX_ROWS][MAX_COLS], matrix2[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS];

    // Get elements of matrices
    inputMatrix(matrix1, rows1, cols1);
    inputMatrix(matrix2, rows2, cols2);

    // Multiply matrices
    multiplyMatrices(result, matrix1, matrix2, rows1, cols1, cols2);

    // Print the result matrix
    printMatrix(result, rows1, cols2);

    return 0;
}