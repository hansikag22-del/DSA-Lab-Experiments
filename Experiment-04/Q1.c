//Find the second largest elements in an array.

#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int largest = arr[0];
    int second = arr[0];

    for (int i = 1; i < n; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }

    for (int i = 0; i < n; i++){
        if(arr[i] > second && arr[i] < largest){
            second = arr[i];
        }
    }
    printf("The second largest element is: %d\n", second);
    return 0;

}