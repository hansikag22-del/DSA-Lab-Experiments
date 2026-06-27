// b.	Check whether the string is palindrome or not using array and Queue.
#include <stdio.h>
#include <string.h>
#define MAX 100

char queue[MAX];
int front = -1, rear = -1;

void insert(char c) 
{
    if (rear == MAX - 1)
        return;
    if (front == -1) 
        front = 0;
        queue[++rear] = c;
}

int isPalindrome(char str[]) 
{
    front = rear = -1; // reset queue
    int len = strlen(str);
    for (int i = 0; i < len; i++) 
    {
        insert(str[i]);
    }
    int i = front, j = rear;
    while (i < j) 
    {
        if (queue[i] != queue[j]) 
            return 0;
        i++; 
        j--;
    }
    return 1;
}

int main() 
{
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str);
    if (isPalindrome(str))
        printf("%s is a palindrome\n", str);
    else
        printf("%s is not a palindrome\n", str);
    return 0;
}