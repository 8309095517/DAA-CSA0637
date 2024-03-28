#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void insert(struct Node** headRef, int position, int data);
void printList(struct Node* head);

// Function to insert a number into a list at a specified position
void insert(struct Node** headRef, int position, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    
    // Insert at the beginning if position is 0 or list is empty
    if (position == 0 || *headRef == NULL) {
        newNode->next = *headRef;
        *headRef = newNode;
    } else {
        struct Node* current = *headRef;
        // Traverse to the position before the insertion point
        for (int i = 0; i < position - 1 && current->next != NULL; i++)
            current = current->next;
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    
    // Insert some numbers into the list
    insert(&head, 0, 5); // Insert 5 at position 0
    insert(&head, 1, 7); // Insert 7 at position 1
    insert(&head, 1, 6); // Insert 6 at position 1
    insert(&head, 3, 8); // Insert 8 at position 3
    
    // Print the list
    printf("List after insertion: ");
    printList(head);
    
    return 0;
}
