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

struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    struct Node* current;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            insertAtEnd(&result, list1->data);
            list1 = list1->next;
        } else {
            insertAtEnd(&result, list2->data);
            list2 = list2->next;
        }
    }

    while (list1 != NULL) {
        insertAtEnd(&result, list1->data);
        list1 = list1->next;
    }

    while (list2 != NULL) {
        insertAtEnd(&result, list2->data);
        list2 = list2->next;
    }

    return result;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    insertAtEnd(&list1, 1);
    insertAtEnd(&list1, 3);
    insertAtEnd(&list1, 5);

    insertAtEnd(&list2, 2);
    insertAtEnd(&list2, 4);
    insertAtEnd(&list2, 6);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    struct Node* mergedList = mergeSortedLists(list1, list2);

    printf("Merged Sorted List: ");
    printList(mergedList);

    return 0;
}

