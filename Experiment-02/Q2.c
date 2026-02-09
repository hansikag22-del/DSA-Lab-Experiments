//Write a program to remove duplicate elements from an array.

#include <stdio.h>
int main(){
    int a[100],n,i,j;

    printf("Enter size of array:");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    //To check duplicates
    for (i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[i]==a[j]){
                a[j]=0;
            }
        }
    }

    printf("After removing duplicates:\n");
    for(i=0; i<n; i++){
        if(a[i] != 0){
            printf("%d ",a[i]);
        }
    }
    return 0;


}