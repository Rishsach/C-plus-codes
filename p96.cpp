#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
};

void push(Node** head_ref, int new_data);

Node* sortedIntersect(Node* a, Node* b)
{
	Node dummy;
	Node* tail = &dummy;
	dummy.next = NULL;

	while (a != NULL && b != NULL) {
		if (a->data == b->data) {
			push((&tail->next), a->data);
			tail = tail->next;
			a = a->next;
			b = b->next;
		}
	
		else if (a->data < b->data)
			a = a->next;
		else
			b = b->next;
	}
	return (dummy.next);
}

void push(Node** head_ref, int new_data)
{

	Node* new_node = (Node*)malloc(
		sizeof(Node));

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}
void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data <<" ";
		node = node->next;
	}
}

int main()
{
	Node* a = NULL;
	Node* b = NULL;
	Node* intersect = NULL;

	push(&a, 6);
	push(&a, 5);
	push(&a, 4);
	push(&a, 3);
	push(&a, 2);
	push(&a, 1);

	push(&b, 8);
	push(&b, 6);
	push(&b, 4);
	push(&b, 2);
	intersect = sortedIntersect(a, b);

	cout<<"Linked list containing common items of a & b \n";
	printList(intersect);
}
