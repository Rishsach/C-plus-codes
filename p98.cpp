
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};
void sortedInsert(Node** head_ref,
				Node* new_node)
{
	Node* current;
	if (*head_ref == NULL
		|| (*head_ref)->data
			>= new_node->data) {
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else {
		current = *head_ref;
		while (current->next != NULL
&& current->next->data
< new_node->data) {
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
}

Node* newNode(int new_data)
{
	Node* new_node = new Node();

	new_node->data = new_data;
	new_node->next = NULL;

	return new_node;
}

void printList(Node* head)
{
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}
int main()
{
	Node* head = NULL;
	Node* new_node = newNode(5);
	sortedInsert(&head, new_node);
	new_node = newNode(10);
	sortedInsert(&head, new_node);
	new_node = newNode(7);
	sortedInsert(&head, new_node);
	new_node = newNode(3);
	sortedInsert(&head, new_node);
	new_node = newNode(1);
	sortedInsert(&head, new_node);
	new_node = newNode(9);
	sortedInsert(&head, new_node);
	cout << "Created Linked List\n";
	printList(head);

	return 0;
}

