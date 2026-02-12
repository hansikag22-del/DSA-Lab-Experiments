/*Design, Develop and Implement a menu-driven Program in C for the following Array operations
a. Creating an Array of N Integer Elements
b. Display of Array Elements with Suitable Headings
c. Inserting an Element (ELEM) at a given valid Position (POS)
d. Deleting an Element at a given valid Position(POS)
e. Exit.
Support the program with functions for each of the above operations.*/

#include <stdio.h>

int a[50], n = 0;

void create() {
    printf("Enter n: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void display() {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void insert() {
    int e, p;
    scanf("%d %d", &e, &p);
    for (int i = n; i >= p; i--)
        a[i] = a[i - 1];
    a[p - 1] = e;
    n++;
}

void delete() {
    int p;
    scanf("%d", &p);
    for (int i = p - 1; i < n - 1; i++)
        a[i] = a[i + 1];
    n--;
}

int main() {
    int ch;
    while (1) {
        printf("\n1.Create 2.Display 3.Insert 4.Delete 5.Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: delete(); break;
            case 5: return 0;
        }
    }
}