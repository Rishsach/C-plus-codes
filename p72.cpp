
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};


void printList(struct Node*);

void push(struct Node **head_ref, int new_data)
{

struct Node* new_node =
			(struct Node*) malloc(sizeof(struct Node));


new_node->data = new_data;

new_node->next = *head_ref;

*head_ref = new_node;
}

void frontAndBackSplit(struct Node *head,
			struct Node **front_ref, struct Node **back_ref)
{
	Node *slow, *fast;
	
	slow = head;
	fast = head->next;
	

	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	
	
	*front_ref = head;
	*back_ref = slow->next;
	slow->next = NULL;
}

void reverseList(struct Node **head_ref)
{
	struct Node *current, *prev, *next;
	current = *head_ref;
	prev = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}
void modifyTheContentsOf1stHalf(struct Node *front,
								struct Node *back)
{
	
	while (back != NULL)
	{
		front->data = front->data - back->data;
		
		front = front->next;
		back = back->next;
	}
}

struct Node* concatFrontAndBackList(struct Node *front,
									struct Node *back)
{
	struct Node *head = front;
	
	while (front->next != NULL)
		front = front->next;
		
	front->next = back;
	
	return head;
}

struct Node* modifyTheList(struct Node *head)
{

	if (!head || head->next == NULL)
		return head;
	
	struct Node *front, *back;
	
	frontAndBackSplit(head, &front, &back);
	
	reverseList(&back);
	
	modifyTheContentsOf1stHalf(front, back);
		
	reverseList(&back);
	
	head = concatFrontAndBackList(front, back);
	
	return head;
}

void printList(struct Node *head)
{
	if (!head)
		return;
	
	while (head->next != NULL)
	{
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << head->data << endl;
}

int main()
{
	struct Node *head = NULL;
	
	push(&head, 10);
	push(&head, 7);
	push(&head, 12);
	push(&head, 8);
	push(&head, 9);
	push(&head, 2);
	
	head = modifyTheList(head);
	
	cout << "Modified List:" << endl;
	printList(head);
	return 0;
}
