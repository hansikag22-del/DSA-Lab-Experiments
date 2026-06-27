/* 2.	Write algorithm and C program, compile, execute and test the code using C compiler with suitable test cases.
a.	Using array and functions implement Circular Queue data structure and its operations like insert, delete, and display.
b.	Using array and functions implement a Queue using stacks.
*/

#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert(int item) 
{
    if ((front == 0 && rear == MAX-1) || (front == rear+1)) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) 
    {
        front = rear = 0;
    } 
    else 
    {
        rear = (rear+1) % MAX;
    }
    queue[rear] = item;
    printf("%d inserted\n", item);
}

void delete() 
{
    if (front == -1) 
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("%d deleted\n", queue[front]);
    if (front == rear) 
    {
        front = rear = -1;
    } 
    else 
    {
        front = (front+1) % MAX;
    }
}

void display() 
{
    if (front == -1) 
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) 
    {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i+1) % MAX;
    }
    printf("\n");
}

int main() 
{
    int choice, item;
    while (1) 
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter item: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}