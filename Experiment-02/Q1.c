//1.Input an array. Print all elements in an array. Each element is printed on a new line.
#include<stdio.h>
int main(){
    int a[100],n;
    printf("Enter number of elements: ");\
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i =0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Array elements:\n");
    for(int i=0;i<n;i++)
       printf("%d\n", a[i]);

    return 0;
}
