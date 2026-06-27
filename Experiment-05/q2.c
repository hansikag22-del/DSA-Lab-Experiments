/*Write a program that takes N strings from the user,stores them in an array of pointers and sorts them in lexicographical order(dictionary order).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n,i,j;
    printf("Enter number of string: ");
    scanf("%d", &n);

    char *str[n];
    for(i=0;i<n;i++){
        str[i]=(char*)malloc(100 * sizeof(char));
        printf("Enter string %d: ",i);
        scanf("%s", str[i]);
    }

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(strcmp(str[i], str[j]) > 0){
                char *temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }

    printf("\nStrings in lexicographical order:\n");
    for(i=0;i<n;i++){
        printf("%s\n", str[i]);
    }

    for(i=0;i<n;i++){
        free(str[i]);
    }
    
    return 0;
}