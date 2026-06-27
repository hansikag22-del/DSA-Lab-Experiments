/*•	You are given an array of n integers. Your task is to sort the array in ascending order using the following approach: Starting from the second element, compare it with the elements before it and insert it at its correct position in the sorted part of the array. Continue this process for all elements in the array, growing the sorted portion one element at a time.
	•	Implement the above sorting logic.
	•	Display the sorted array.
	•	Count and print the number of comparisons and shifts (element movements) performed during the sorting process.
*/

#include <stdio.h>

int main() {
    int arr[100], n, i, j, key;
    int comparisons = 0, shifts = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];  // shift
            shifts++;
            j--;
        }

        if(j >= 0) comparisons++; // last comparison

        arr[j + 1] = key;  // insert
    }

    printf("\nSorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nComparisons: %d", comparisons);
    printf("\nShifts: %d", shifts);

    return 0;
}