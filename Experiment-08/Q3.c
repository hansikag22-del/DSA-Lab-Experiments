/* 3.	Implement a Circular Queue using array. Write an algorithm to check if a queue is full or empty.
Perform the following operations on a queue:
Enqueue: 10, 20, 30
Dequeue one element
Enqueue: 40
Show the final state of the queue.
*/

#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Function to check if queue is empty
int isEmpty() {
    return front == -1;
}

// Function to check if queue is full
int isFull() {
    // Queue is full if front is at 0 and rear is at last index
    // OR if front is just ahead of rear (circular condition)

    return (front == 0 && rear == MAX-1) || (front == rear+1);
}

// Function to insert an element into the queue
void enqueue(int item) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    // If queue is empty, initialize front and rear
    if (isEmpty()) {
        front = rear = 0;
    } 
    else {
        rear = (rear+1) % MAX;
    }
    queue[rear] = item;
    printf("%d enqueued\n", item);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }
    printf("%d dequeued\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front+1) % MAX;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i+1) % MAX;
    }
    printf("\n");
}

int main() {
    // Perform operations as per question
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    enqueue(40);
    display();
    return 0;
}