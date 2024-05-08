#include<stdio.h>

int main() {
    int row = 3, col = 4;
    int augmentedMatrix[row][col];

    // Enter data row wise for augmented matrix
    printf("Enter data for Augmented Matrix Row Wise : ");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &augmentedMatrix[i][j]);
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i > j) {
                double val = (double)augmentedMatrix[i][j] / augmentedMatrix[j][j];
                for (int k = 0; k < row + 1; k++) {
                    augmentedMatrix[i][k] = augmentedMatrix[i][k] - val * augmentedMatrix[j][k];
                }
            }
        }
    }

    printf("\nAfter Row Operations\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", augmentedMatrix[i][j]);
            if (j == 2) {
                printf(" | ");
            }
        }
        printf("\n");
    }

    float zVal;
    if(augmentedMatrix[2][3] == 0){
        zVal = 0;
    } else{
        zVal = augmentedMatrix[2][3]/augmentedMatrix[2][2];
    }

    float yVal = (augmentedMatrix[1][3] - augmentedMatrix[1][2] * zVal)/augmentedMatrix[1][1];
    float xVal = (augmentedMatrix[0][3] - augmentedMatrix[0][2]*zVal - augmentedMatrix[0][1]*yVal)/augmentedMatrix[0][0];
    
    //Values
    printf("\nThe Value of x : %f\n", xVal);
    printf("The Value of y : %f\n", yVal);
    printf("The Value of z : %f\n", zVal);

    return 0;
}