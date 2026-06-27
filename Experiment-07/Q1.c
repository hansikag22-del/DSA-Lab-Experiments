#include <stdio.h>
#include <string.h>

#define MAX 100

// Stack to store words
char stack[MAX][MAX];
int top = -1;

// Push function
void push(char word[]) {
    if (top < MAX - 1) {
        top++;
        strcpy(stack[top], word);
    }
}

// Pop function
char* pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return NULL;
}

int main() {
    char sentence[200];
    char word[50];
    int i = 0, j = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove newline character
    sentence[strcspn(sentence, "\n")] = '\0';

    // Traverse sentence
    while (sentence[i] != '\0') {
        if (sentence[i] != ' ') {
            word[j++] = sentence[i];
        } else {
            word[j] = '\0';
            push(word);
            j = 0;
        }
        i++;
    }

    // Push last word
    word[j] = '\0';
    push(word);

    // Pop and print reversed sentence
    printf("Reversed sentence: ");
    while (top >= 0) {
        printf("%s ", pop());
    }

    return 0;
}