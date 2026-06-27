#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX][100]; // Stack to store actions (strings)
int top = -1;

// Push operation (Perform Action)
void push(char action[]) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot perform more actions.\n");
    } else {
        top++;
        strcpy(stack[top], action);
        printf("Action performed: %s\n", action);
    }
}

// Pop operation (Undo Action)
void pop() {
    if (top == -1) {
        printf("No actions to undo!\n");
    } else {
        printf("Undo action: %s\n", stack[top]);
        top--;
    }
}

// Display stack
void display() {
    if (top == -1) {
        printf("No actions performed yet.\n");
    } else {
        printf("\nCurrent Actions (Latest to Oldest):\n");
        for (int i = top; i >= 0; i--) {
            printf("%s\n", stack[i]);
        }
    }
}

int main() {
    int choice;
    char action[100];

    do {
        printf("\n--- Self-Service Kiosk Menu ---\n");
        printf("1. Perform Action\n");
        printf("2. Undo Last Action\n");
        printf("3. Display Actions\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume newline

        switch (choice) {
            case 1:
                printf("Enter action (e.g., Select Seat A1, Add Popcorn): ");
                fgets(action, sizeof(action), stdin);
                action[strcspn(action, "\n")] = '\0'; // remove newline
                push(action);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}