//C program to Insert an Element in the Sorted Array.

#include <stdio.h>
int main(){
    int n, i, element;
    scanf("%d", &n);

    int arr[n + 1];
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    scanf("%d", &element);

    for (i = n-1; i >= 0 && arr[i] > element; i--){
        arr[i+1]=arr[i];

    }
    arr[i+1]=element;
    for (i=0;i<=n;i++){
        printf("%d ", arr[i]);

    }

    return 0;
}