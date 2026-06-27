/*Write a C program that stores multiple strings using an array of pointers and reverses each string in place.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n,i,j,len;
    printf("Enter number of strings: ");
    scanf("%d", &n);

    char *str[n];

    for(i=0;i<n;i++)
    {
        str[i] =(char*)malloc(100 * sizeof(char));
        printf("Enter string %d: ",i);
        scanf("%s", str[i]);

    }

    for(i=0;i<n;i++){
        len=strlen(str[i]);
        for(j=0;j<len/2;j++){
            char temp = str[i][j];
            str[i][j]=str[i][len - j-1];
            str[i][len-j-1]=temp;
        }
    }
    printf("\nReversed strings:\n");
    for(i = 0; i < n; i++) {
        printf("%s\n", str[i]);
    }
    
    for(i = 0; i < n; i++) {
        free(str[i]);
    }
    
    return 0;
}