#include <bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	struct Node* next;
};

void deleteLast(struct Node* head, int x)
{
	struct Node *temp = head, *ptr = NULL;
	while (temp) {

		if (temp->data == x)
			ptr = temp;	
		temp = temp->next;
	}

	if (ptr != NULL && ptr->next == NULL) {
		temp = head;
		while (temp->next != ptr)
			temp = temp->next;	
		temp->next = NULL;
	}

	if (ptr != NULL && ptr->next != NULL) {
		ptr->data = ptr->next->data;
		temp = ptr->next;
		ptr->next = ptr->next->next;
		free(temp);
	}
}

struct Node* newNode(int x)
{
	Node* node = new Node ;
	node->data = x;
	node->next = NULL;
	return node;
}
void display(struct Node* head)
{
	struct Node* temp = head;
	if (head == NULL) {
		cout <<"NULL\n";
		return;
	}
	while (temp != NULL) {
		cout <<" --> "<< temp->data;
		temp = temp->next;
	}
	cout <<"NULL\n";
}
int main()
{
	struct Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	head->next->next->next->next->next = newNode(4);
	head->next->next->next->next->next->next = newNode(4);
	cout <<"Created Linked list: ";
	display(head);
	deleteLast(head, 4);
	cout <<"List after deletion of 4: ";
	display(head);
	return 0;
}

