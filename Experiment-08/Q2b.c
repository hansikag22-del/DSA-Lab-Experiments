//b.	Using array and functions implement a Queue using stacks.
#include <stdio.h>
#define MAX 50

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void push1(int item) 
{
    if (top1 == MAX-1) 
    {
        printf("Stack1 Overflow\n");
        return;
    }
    stack1[++top1] = item;
}

void push2(int item) 
{
    if (top2 == MAX-1) 
    {
        printf("Stack2 Overflow\n");
        return;
    }
    stack2[++top2] = item;
}

int pop1() 
{
    if (top1 == -1) 
    return -1;
    return stack1[top1--];
}

int pop2() 
{
    if (top2 == -1)
    return -1;
    return stack2[top2--];
}

void insert(int item) 
{
    push1(item);
    printf("%d inserted\n", item);
}

void delete() 
{
    if (top1 == -1 && top2 == -1) 
    {
        printf("Queue Underflow\n");
        return;
    }
    if (top2 == -1) 
    {
        while (top1 != -1) 
        {
            push2(pop1());
        }
    }
    int val = pop2();
    printf("%d deleted\n", val);
}

void display() 
{
    if (top1 == -1 && top2 == -1) 
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = top2; i >= 0; i--) 
    {
        printf("%d ", stack2[i]);
    }
    for (int i = 0; i <= top1; i++) 
    {
        printf("%d ", stack1[i]);
    }
    printf("\n");
}

int main() {
    int choice, item;
    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
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