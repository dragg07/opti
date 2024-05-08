#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define SIZE 10

int main()
{
     float A[SIZE][SIZE], temp;
     int i,j,k,n;
     /* Inputs */
     /* 1. Reading order of matrix */
     printf("Enter order of matrix: ");
     scanf("%d", &n);
     /* 2. Reading Matrix */
     printf("Enter coefficients of Matrix:\n");
     for(i=1;i<=n;i++)
     {
          for(j=1;j<=n;j++)
          {
               printf("A[%d][%d] = ",i,j);
               scanf("%f", &A[i][j]);
          }
     }

     printf("The coefficient matrix:\n");
     for(i=1;i<=n;i++)
     {
        for(j=1;j<=n;j++)
        {
            printf("%.2f  ",A[i][j]);
        }
        printf("\n");
     }

     /* Augmenting Identity Matrix of Order n */
     for(i=1;i<=n;i++)
     {
          for(j=1;j<=n;j++)
          {
               if(i==j)
               {
                    A[i][j+n] = 1;
               }
               else
               {
                    A[i][j+n] = 0;
               }
          }
     }

     printf("\nThe augmented matrix is:\n");
     for(i=1;i<=n;i++)
     {
        for(j=1;j<=2*n;j++)
        {
            printf("%.2f  ",A[i][j]);
        }
        printf("\n");
     }


     //Applying Gauss Jordan Elimination 
     for(i=1;i<=n;i++)
     {
          if(A[i][i] == 0.0)
          {
               printf("Mathematical Error!");
               exit(0);
          }
          for(j=1;j<=n;j++)
          {
               if(i!=j)
               {
                    temp = A[j][i]/A[i][i];
                    for(k=1;k<=2*n;k++)
                    {
                         A[j][k] = A[j][k] - temp*A[i][k];
                    }
               }
          }
     }
     /* Row Operation to Make Principal Diagonal to 1 */
     for(i=1;i<=n;i++)
     {
          for(j=n+1;j<=2*n;j++)
          {
               A[i][j] = A[i][j]/A[i][i];
          }
     }
     
    
     /* Displaying Inverse Matrix */
     printf("\nThe inverse matrix is:\n");
     for(i=1;i<=n;i++)
     {
          for(j=n+1;j<=2*n;j++)
          {
               printf("%0.3f\t",A[i][j]);
          }
          printf("\n");
     }return(0);
}