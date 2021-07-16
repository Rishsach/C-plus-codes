#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};


void deleteLast(struct Node** head, int x)
{
	struct Node** tmp1 = NULL;
	while (*head)
	{
			if ((*head)->data == x)
			{
				tmp1 = head;
			}
			head = &(*head)->next;
	}
	if (tmp1)
	{
		struct Node* tmp = *tmp1;
		*tmp1 = tmp->next;
		free(tmp);
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
	if (head == NULL)
	{
		cout << "NULL\n";
		return;
	}
	while (temp != NULL)
	{
		cout << temp->data <<" --> ";
		temp = temp->next;
	}
	cout << "NULL\n";
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
	
	cout << "Created Linked list: ";
	display(head);
	

	deleteLast(&head, 4);
	cout << "List after deletion of 4: ";
	
	display(head);
	
	return 0;
}


