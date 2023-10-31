#include <stdio.h>
#include <stdlib.h>
struct Node
{
int data;
struct Node* prev;
struct Node* next;
};
struct Node* createNode(int data)
{
struct Node* newNode = (struct Node*)malloc(sizeof(struct
Node));
newNode->data = data;
newNode->prev = NULL;
newNode->next = NULL;
return newNode;
}
void insertAtBeginning(struct Node** head, int data)
{
struct Node* newNode = createNode(data);
if (*head == NULL)
{
*head = newNode;
}
else
{
newNode->next = *head;
(*head)->prev = newNode;
*head = newNode;
}
}
void insertAtpos(struct Node** head, int n, int data)
{
struct Node* newNode = createNode(data);
if (*head == NULL)
{
*head = newNode;
}
else
{
struct Node* current = *head;
int i = 1;
while (i < n && current->next != NULL)
{
current = current->next;
i++;
}
newNode->next = current->next;
if (current->next != NULL)
{
current->next->prev = newNode;
}
current->next = newNode;
newNode->prev = current;
}
}
void insertAtEnd(struct Node** head, int data)
{
struct Node* newNode = createNode(data);
if (*head == NULL)
{
*head = newNode;
}
else
{
struct Node* current = *head;
while (current->next != NULL)
{
current = current->next;
}
current->next = newNode;
newNode->prev = current;
}
}
void deleteNode(struct Node** head, int data)
{
if (*head == NULL)
return;
struct Node* current = *head;
while (current != NULL && current->data != data)
{
current = current->next;
}
if (current == NULL)
return;
if (current->prev != NULL)
{
current->prev->next = current->next;
}
else
{
*head = current->next;
}
if (current->next != NULL)
{
current->next->prev = current->prev;
}
free(current);
}
void print(struct Node* head)
{
struct Node* current = head;
while (current != NULL)
{
printf("%d ", current->data);
current = current->next;
}
}
int main()
{
struct Node* head = NULL;
int n;
printf("Enter the number of elements: ");
scanf("%d", &n);
for (int i = 0; i < n; i++)
{
printf("Enter the element: ");
int data;
scanf("%d", &data);
insertAtEnd(&head, data);
}
printf("Original list: ");
print(head);
printf("\nMenu!\n1-Insert data at beginning.\n2-Insert data at end.\n3-Insert in the given position.\n4-Delete node.\nEnter your choice: ");
int choice;
scanf("%d", &choice);
switch (choice)
{
case 1:
int newd;
printf("Enter the element: ");
scanf("%d", &newd);
insertAtBeginning(&head, newd);
printf("List after insertion: ");
print(head);
break;
case 2:
printf("Enter the element: ");
scanf("%d", &newd);
insertAtEnd(&head, newd);
printf("List after insertion: ");
print(head);
break;
case 3:
	int pos;
printf("Enter the element: ");
scanf("%d", &newd);
printf("Enter the position: ");
scanf("%d", &pos);
insertAtpos(&head, pos, newd);
printf("List after insertion: ");
print(head);
break;
case 4:
printf("Enter the element: ");
scanf("%d", &newd);
deleteNode(&head, newd);
printf("List after deletion: ");
print(head);
break;
default:
printf("Wrong choice!");
}
return 0;
}
