//1.Write a c program to print the Fibonacci series without using recursion and using recursion.

/*Fibonacci series without using recursion.
#include <stdio.h>
int main(){
    int n,a=0,b=1,c;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    for(int i = 1; i<= n; i++){
        printf("%d ", a);
        c=a +b;
        a=b;
        b=c;
    }
    return 0;

}*/

//Fibonacci Series using recursion.
#include <stdio.h>
int fib(int n){
    if (n<=1)
        return n;
    return fib(n-1)+fib(n-2);
}

int main(){
    int n;
    printf("Enter a term: ");
    scanf("%d", &n);

    for (int i=0; i<n;i++)
       printf("%d",fib(i));

    return 0;
}