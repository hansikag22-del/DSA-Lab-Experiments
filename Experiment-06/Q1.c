/*xA university is organizing a technical workshop where students can register online. The number of participants is not fixed, and registrations can occur at any time.
Design a linked list–based event registration system that supports the following operations:
Register a new participant.
Display all registered participants.
Search for a participant using their registration ID.
Count the total number of registered participants.
Tasks:
Define the structure of the participant node.
Explain how the linked list will store participant information.
Write the algorithm or program for each operation.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition
struct Participant {
    int regID;
    char name[50];
    struct Participant *next;
};

struct Participant *head = NULL;

// Register new participant
void registerParticipant() {
    struct Participant *newNode, *temp;

    newNode = (struct Participant*)malloc(sizeof(struct Participant));

    printf("Enter Registration ID: ");
    scanf("%d", &newNode->regID);

    printf("Enter Name: ");
    scanf("%s", newNode->name);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Display all participants
void displayParticipants() {
    struct Participant *temp = head;

    if (temp == NULL) {
        printf("No participants registered\n");
        return;
    }

    while (temp != NULL) {
        printf("ID: %d  Name: %s\n", temp->regID, temp->name);
        temp = temp->next;
    }
}

// Search participant
void searchParticipant() {
    int id;
    struct Participant *temp = head;

    printf("Enter Registration ID to search: ");
    scanf("%d", &id);

    while (temp != NULL) {
        if (temp->regID == id) {
            printf("Participant Found\n");
            printf("ID: %d Name: %s\n", temp->regID, temp->name);
            return;
        }
        temp = temp->next;
    }

    printf("Participant not found\n");
}

// Count participants
void countParticipants() {
    struct Participant *temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Total Participants: %d\n", count);
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n1. Register Participant\n");
        printf("2. Display Participants\n");
        printf("3. Search Participant\n");
        printf("4. Count Participants\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerParticipant();
                break;

            case 2:
                displayParticipants();
                break;

            case 3:
                searchParticipant();
                break;

            case 4:
                countParticipants();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

