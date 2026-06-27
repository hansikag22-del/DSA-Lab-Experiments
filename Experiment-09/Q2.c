/*	2.	You are given an array of n integers. Your task is to sort the array in ascending order using the following approach: At each step, find the minimum element from the unsorted portion of the array and place it at the beginning of that portion by swapping it with the current position. Repeat this process until the array is sorted.
	•	Implement the above sorting logic.
	•	Display the sorted array.
	•	Count and print the number of comparisons and swaps performed during the sorting process.*/

    #include <stdio.h>

int main() {
    int n, i, j, min_index, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int comparisons = 0, swaps = 0;

    // Selection Sort
    for(i = 0; i < n - 1; i++) {
        min_index = i;

        for(j = i + 1; j < n; j++) {
            comparisons++;
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        // Swap if needed
        if(min_index != i) {
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
            swaps++;
        }
    }

    // Print sorted array
    printf("\nSorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Print counts
    printf("\nComparisons: %d", comparisons);
    printf("\nSwaps: %d", swaps);

    return 0;
}

//Idea of Selection Sort
// Divide array into sorted + unsorted part
// Repeatedly:
// Find minimum element from unsorted part
// Swap it with first element of unsorted part