//Write a C program to find the sum of the main diagonal elements of a matrix.

#include <stdio.h>
int main(){
    int n;
    printf("Enter square matrix: ");
    scanf("%d", &n);

    int matrix[n][n];
    int sum = 0;

    printf("Enter the eelements of the matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < n; i++){
        sum += matrix[i][i];
    }

    printf("Sum of min diagonal elements =%d\n", sum);
    return 0;

}