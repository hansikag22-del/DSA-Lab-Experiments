//Write a program to find the largest element in an array using function.

#include <stdio.h>
int largest(int a[],int n)
{
    int i, max = a[0];
    for(i=1;i<n;i++)
    if(a[i]>max)
    max=a[i];
    return max;


}

int main(){
    int a[5]={10,20,30,40,50};
    printf("Largest = %d",largest(a,5));
    return 0;

}