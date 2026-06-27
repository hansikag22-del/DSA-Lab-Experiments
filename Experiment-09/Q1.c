/* 1.You are given an array of n integers. Your task is to sort the array in ascending order using the following approach: Repeatedly compare adjacent elements in the array and swap them if they are in the wrong order. This process is continued until the array becomes completely sorted. After each complete pass through the array, the largest unsorted element settles at its correct position.
	•	Implement the above sorting logic.
	•	Display the sorted array.
	•	Count and print the number of comparisons and swaps performed during the sorting process.*/

#include <stdio.h>

int main() {
    int n, i, j, temp;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {   //Takes n values from the user and stores them in the array.
        scanf("%d", &arr[i]);
    }

    int comparisons = 0, swaps = 0;

    // Bubble Sort
    for(i = 0; i < n - 1; i++) { //After each pass, the largest element moves to the end 
        for(j = 0; j < n - i - 1; j++) {    //Compares adjacent elements
            comparisons++;
            if(arr[j] > arr[j + 1]) { //If left element is greater then swap needed
                // Swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
    }

    // Display sorted array
    printf("\nSorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Print counts
    printf("\nComparisons: %d", comparisons);
    printf("\nSwaps: %d", swaps);

    return 0;
}


/*How Bubble Sort Works (Simple Idea)
Compare adjacent elements
Swap if wrong order
After each pass then largest element goes to last
Repeat until sorted*/