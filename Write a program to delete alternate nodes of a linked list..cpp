#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void deleteAlternateNodes(struct Node* head) {
    if (head == NULL) {
        return;
    }

    struct Node* current = head;
    struct Node* nextNode;

    while (current != NULL && current->next != NULL) {
        nextNode = current->next;
        current->next = nextNode->next;
        free(nextNode);
        current = current->next;
    }
}

int main() {
    struct Node* head = NULL;

    for (int i = 1; i <= 6; i++) {
        insertAtEnd(&head, i);
    }

    printf("Original Linked List: ");
    printList(head);

    deleteAlternateNodes(head);

    printf("Linked List after Deleting Alternate Nodes: ");
    printList(head);

    return 0;
}

