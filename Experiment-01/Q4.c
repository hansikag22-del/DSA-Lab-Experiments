// reverse an array using pointers.
// Reverse an array using pointers

#include <stdio.h>

// Function to reverse array using pointers
void reverseArray(int *arr, int n) {
    int *start = arr;          // pointer to first element
    int *end = arr + n - 1;    // pointer to last element
    int temp;

    while(start < end) {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    reverseArray(arr, n);

    printf("\nReversed array:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}


