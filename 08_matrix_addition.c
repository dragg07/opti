#include <stdio.h>

int main() {
    int m, n, p, q;

    printf("Enter the number of rows and columns of first matrix: ");
    scanf("%d %d", &m, &n);
    int A[m][n];

    printf("Enter the elements of first matrix: ");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter the number of rows and columns of second matrix: ");
    scanf("%d %d", &p, &q);

    if (m != p || n != q) {
        printf("Matrices cannot be added.\n");
        return 1;
    }

    int B[p][q];

    printf("Enter the elements of second matrix: ");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    printf("Sum of matrices:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", A[i][j] + B[i][j]);
        }
        printf("\n");
    }

    return 0;
}