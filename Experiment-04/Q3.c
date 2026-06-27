//Write a C program to check the Identity matrix.

#include <stdio.h>
int main(){
    int n,count = 0;
    scanf("%d",&n);

    int matrix[n][n];
    for(int i = 0;i<n;i++){
        for (int j=0;j<n;j++)
        scanf("%d", &matrix[i][j]);
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if(i != j){
                if (matrix[i][j] != 0)
                count +=1;
            }
            else
            if(matrix[i][j] != 1)
            count +=1;
        }
    }
    if(count==0)
    print("identity matrix");
    else
    print("not identity matrix");
    return 0;
}

