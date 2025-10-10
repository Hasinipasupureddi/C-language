#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

// Insert at Beginning
void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head){
            temp = temp->next;}
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    printf("%d inserted at the beginning.\n", value);
}

// Insert at End
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head){
            temp = temp->next;}
        temp->next = newNode;
        newNode->next = head;
    }
    printf("%d inserted at the end.\n", value);
}

// Insert at a given position
void insertAtPosition(int value, int position) {
    if (position < 1) {
        printf("Invalid position for insertion.\n");
        return;
    }
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }
    struct Node* newNode = createNode(value);
    struct Node* current = head;
    int count = 1;
    while (count < position - 1 && current->next != head) {
        current = current->next;
        count++;
    }
    if (count != position - 1 && current->next == head && position > count + 1) {
        printf("Position out of bounds for insertion.\n");
        free(newNode);
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
    printf("%d inserted at position %d.\n", value, position);
}

// Delete from Beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    struct Node* temp = head;
    if (head->next == head) { // Only one node
        head = NULL;
    } else {
        struct Node* last = head;
        while (last->next != head){
            last = last->next;}
        head = head->next;
        last->next = head;
    }
    printf("%d deleted from the beginning.\n", temp->data);
    free(temp);
}

// Delete from End
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    struct Node* temp = head;
    if (head->next == head) { // Only one node
        head = NULL;
    } else {
        struct Node* prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
    }
    printf("%d deleted from the end.\n", temp->data);
    free(temp);
}

// Delete from given position
void deleteFromPosition(int position) {
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    if (position < 1) {
        printf("Invalid position for deletion.\n");
        return;
    }
    if (position == 1) {
        deleteFromBeginning();
        return;
    }
    struct Node* current = head;
    struct Node* prev = NULL;
    int count = 1;
    while (count < position && current->next != head) {
        prev = current;
        current = current->next;
        count++;
    }
    if (count != position) {
        printf("Position out of bounds for deletion.\n");
        return;
    }
    prev->next = current->next;
    printf("%d deleted from position %d.\n", current->data, position);
    free(current);
}

// Display
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    int choice, value, position;
    do {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(value, position);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter position to delete from: ");
                scanf("%d", &position);
                deleteFromPosition(position);
                break;
            case 7:
                displayList();
                break;
            case 8:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}