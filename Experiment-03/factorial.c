// 3.Write a c program to print the factorial of a number.
#include <stdio.h>
int main(){
    int n, fact = 1;
    printf("Enter a number: ");
    scanf("%d", &n);

    while(n>0){
        fact = fact * n;
        n--;

    }
    printf("Factorial = %d", fact);
    return 0;
}
