//5.Take a new array of integers (positive and negative).Replace all negative numbers with 0 in an array. Return an array with no negative numbers.

#include <stdio.h>

int main() {
    int n, a[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < n; i++) {
        if (a[i] < 0)
            a[i] = 0;
    }

    printf("Array after replacing negatives:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}