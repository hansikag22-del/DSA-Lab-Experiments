//3.Add all elements of an array. Return the sum of all elements.

#include <stdio.h>
int main(){
    int n,a[100],sum =0;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i=0;i<n;i++)
       scanf("%d",&a[i]);

    for (int i=0;i<n;i++)
        sum += a[i];
    
    printf("Sum = %d", sum);
    return 0;
}