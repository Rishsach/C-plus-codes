
#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* next;
};

void printReverse(struct Node** head_ref, int n)
{
	int j = 0;
	struct Node* current = *head_ref;
	while (current != NULL) {

		for (int i = 0; i < 2 * (n - j); i++)
			printf(" ");

		printf("%d\r", current->data);

		current = current->next;
		j++;
	}
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node =
		(struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

int printList(struct Node* head)
{
	int i = 0;
	struct Node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
		i++;
	}
	return i;
}

int main()
{
	struct Node* head = NULL;

	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	push(&head, 6);

	printf("Given linked list:\n");
	
	int n = printList(head);

	printf("\nReversed Linked list:\n");
	printReverse(&head, n);
	printf("\n");
	return 0;
}
