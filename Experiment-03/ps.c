//2.Write a c program to check the palindrome number.

#include <stdio.h>
int main(){
    int n,r,rev = 0;
    printf("Enter a number: ");
    scanf("%d", &n);

    int t =n;
    while(n != 0){
        r=n%10;
        rev=rev*10+r;
        n =n/10;
    }

    if (t == rev)
       printf("Palindrome");
    else
       printf("Not Palindrome");
    return 0;

}