/*Write a program where the user enters N strings.Allow the user to choose two indices and swap the corresponding strings.*/

#include <stdio.h>
#include <string.h>
int main(){
    int n,i,index1,index2;
    printf("Enter number of strings: ");
    scanf("%d", &n);

    char str[n][100];
    for (i = 0;i<n;i++){
        printf("Enter string %d: ",i);
        scanf("%s", str[i]);
    }

    printf("\nEnter first index to swap: ");
    scanf("%d", &index1);

    printf("\nEnter second index to swap: ");
    scanf("%d", &index2);

    if(index1 >= 0 && index1 < n && index2 >= 0 && index2 <n){
        char temp[100];
        strcpy(temp, str[index1]);
        strcpy(str[index1], str[index2]);
        strcpy(str[index2],temp);

        printf("\nAfter swapping:\n");
        for(i = 0;i<n;i++){
            printf("%s\n",str[i]);
        }
    }else{
        printf("Invalid indices!");
    }
    return 0;
}