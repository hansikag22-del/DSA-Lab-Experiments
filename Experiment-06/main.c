/* Q1. A university is organizing a technical workshop where students can register online. The number of participants 
is not fixed, and registrations can occur at any time. Design a linked list–based event registration system that supports 
the following operations: Register a new participant. Display all registered participants. Search for a participant using
their registration ID. Count the total number of registered participants. Tasks: Define the structure of the participant 
node. Explain how the linked list will store participant information. Write the algorithm or program for each operation. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Structure for Participant Node
struct Participant {
    int regID;                     // Unique Registration ID
    char name[50];                 // Participant Name
    struct Participant* next;      // Pointer to next node
};


// Function to Register a New Participant (generic linked list insert at end)
void registerParticipant(struct Participant** head, int id, char name[]) {
    struct Participant* newNode = (struct Participant*)malloc(sizeof(struct Participant));
    newNode->regID = id;
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Participant* temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
}

// Function to Display All Participants
void displayParticipants(struct Participant* head) {
    if (head == NULL) {
        printf("No participants.\n");
        return;
    }
    struct Participant* temp = head;
    while (temp != NULL) {
        printf("ID: %d, Name: %s\n", temp->regID, temp->name);
        temp = temp->next;
    }
}

// Function to Search Participant by ID
struct Participant* searchParticipant(struct Participant* head, int id) {
    struct Participant* temp = head;
    while (temp != NULL) {
        if (temp->regID == id) return temp;
        temp = temp->next;
    }
    return NULL;
}


// Function to Count Total Participants
int countParticipants(struct Participant* head) {
    int count = 0;
    struct Participant* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}


// Function to Delete a Participant by ID
// Handles first, middle, last node cases
void deleteParticipant(struct Participant** head, int id) {
    struct Participant* temp = *head;
    struct Participant* prev = NULL;

    // Case 1: Head node
    if (temp != NULL && temp->regID == id) {
        *head = temp->next;
        free(temp);
        printf("Deleted participant with ID %d.\n", id);
        return;
    }

    // Traverse to find node
    while (temp != NULL && temp->regID != id) {
        prev = temp;
        temp = temp->next;
    }

    // Not found
    if (temp == NULL) {
        printf("Participant with ID %d not found.\n", id);
        return;
    }

    // Case 2 & 3: Middle or Last node
    prev->next = temp->next;
    free(temp);
    printf("Deleted participant with ID %d.\n", id);
}


// Register with Capacity (100 max)
// If full, add to waiting list
void registerWithCapacity(struct Participant** registeredHead,
                          struct Participant** waitingHead,
                          int id, char name[]) {
    if (countParticipants(*registeredHead) < 100) {
        registerParticipant(registeredHead, id, name);
        printf("Participant registered in main list.\n");
    } else {
        registerParticipant(waitingHead, id, name);
        printf("Capacity full! Added to waiting list.\n");
    }
}


// Move first waiting participant to registered list
void moveFromWaiting(struct Participant** registeredHead,
                     struct Participant** waitingHead) {
    if (*waitingHead == NULL) return; // No one waiting

    struct Participant* temp = *waitingHead;
    *waitingHead = temp->next; // Remove from waiting list

    // Insert into registered list
    temp->next = NULL;
    if (*registeredHead == NULL) {
        *registeredHead = temp;
    } else {
        struct Participant* r = *registeredHead;
        while (r->next != NULL) r = r->next;
        r->next = temp;
    }
    printf("Moved waiting participant (ID: %d, Name: %s) to registered list.\n",
           temp->regID, temp->name);
}


// Main Function (Menu-driven)
int main() {
    struct Participant* registeredHead = NULL; // Registered participants list
    struct Participant* waitingHead = NULL;    // Waiting list
    int choice, id;
    char name[50];

    while (1) {
        printf("\n===== Event Registration System =====\n");
        printf("1. Register Participant\n");
        printf("2. Display Registered Participants\n");
        printf("3. Display Waiting List\n");
        printf("4. Search Participant by ID\n");
        printf("5. Count Registered Participants\n");
        printf("6. Delete Participant\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Registration ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                registerWithCapacity(&registeredHead, &waitingHead, id, name);
                break;

            case 2:
                printf("\n--- Registered Participants ---\n");
                displayParticipants(registeredHead);
                break;

            case 3:
                printf("\n--- Waiting List ---\n");
                displayParticipants(waitingHead);
                break;

            case 4:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                struct Participant* found = searchParticipant(registeredHead, id);
                if (found) {
                    printf("Found in Registered List -> ID: %d, Name: %s\n", found->regID, found->name);
                } else {
                    found = searchParticipant(waitingHead, id);
                    if (found)
                        printf("Found in Waiting List -> ID: %d, Name: %s\n", found->regID, found->name);
                    else
                        printf("Participant not found.\n");
                }
                break;

            case 5:
                printf("Total Registered Participants: %d\n", countParticipants(registeredHead));
                break;

            case 6:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteParticipant(&registeredHead, id);
                // After deletion, move waiting participant if space available
                if (countParticipants(registeredHead) < 100) {
                    moveFromWaiting(&registeredHead, &waitingHead);
                }
                break;

            case 7:
                printf("Exiting... Thank you!\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}