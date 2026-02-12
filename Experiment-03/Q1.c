//4.Write a c program to check the Armstrong number.
#include <stdio.h>
int main(){
    int n,r,sum=0,t;
    printf("Enter a number: ");
    scanf("%d", &n);

    t =n;
    while(n != 0){
        r=n % 10;
        sum = sum + r*r*r;
        n=n/10;

    }
    if(sum == t)
      printf("Armstrong");
    else
      printf("Not a armstrong");
    
    return 0;


}
