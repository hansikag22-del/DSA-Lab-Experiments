//Take an array and a target number as input and check if a number exists in an array.return True if the number exists, otherwise False.

#include <stdio.h>

int main() {
    int n, a[100], target, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter target number: ");
    scanf("%d", &target);

    for (int i = 0; i < n; i++) {
        if (a[i] == target) {
            found = 1;
            break;
        }
    }

    if (found)
        printf("True");
    else
        printf("False");

    return 0;
}