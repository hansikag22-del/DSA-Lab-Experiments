/*Write a C program that takes a word and a sentence stored in an array of pointers and checks if the word exists in the sentence.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *sentence;
    char word[100];
    
    // Allocates memory for sentence
    sentence = (char*)malloc(200 * sizeof(char));
    
    printf("Enter a sentence: ");
    getchar();   
    fgets(sentence, 200, stdin);
    
    printf("Enter word to search: ");
    scanf("%s", word);
    
    // Removing newline from sentence 
    sentence[strcspn(sentence, "\n")] = '\0';
    
    // Checking if word exists
    if (strstr(sentence, word) != NULL) {
        printf("Word found in the sentence.\n");
    } else {
        printf("Word not found in the sentence.\n");
    }
    
    free(sentence);
    
    return 0;
}