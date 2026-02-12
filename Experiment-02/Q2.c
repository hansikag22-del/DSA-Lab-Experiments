//2.Find the largest and smallest number in an array of integers.

#include <stdio.h>
int main(){
    int n,a[100],i;
    int max, min;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i=0;i<n;i++)
      scanf("%d", &a[i]);

    max=min=a[0];
    for(i=1;i<n;i++){
        if (a[i] > max)
           max = a[i];
        if (a[i] < min)
           min = a[i];
    }

    printf("Largest =%d\n", max);
    printf("Smallest =%d", min);

    return 0;
}
