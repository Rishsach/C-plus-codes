#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
	Node *prev;
	int info;
	Node *next;
};

void nodeInsetail(Node **head,
				Node **tail,
				int key)
{

	Node *p = new Node();
	p->info = key;
	p->next = NULL;

	if ((*head) == NULL)
	{
		(*head) = p;
		(*tail) = p;
		(*head)->prev = NULL;
		return;
	}

	if ((p->info) < ((*head)->info))
	{
		p->prev = NULL;
		(*head)->prev = p;
		p->next = (*head);
		(*head) = p;
		return;
	}

	if ((p->info) > ((*tail)->info))
	{
		p->prev = (*tail);
		(*tail)->next = p;
		(*tail) = p;
		return;
	}

	Node *temp = (*head)->next;
	while ((temp->info) < (p->info))
		temp = temp->next;

	(temp->prev)->next = p;
	p->prev = temp->prev;
	temp->prev = p;
	p->next = temp;
}

void printList(Node *temp)
{
	while (temp != NULL)
	{
		cout << temp->info << " ";
		temp = temp->next;
	}
}
int main()
{
	Node *left = NULL, *right = NULL;
	nodeInsetail(&left, &right, 30);
	nodeInsetail(&left, &right, 50);
	nodeInsetail(&left, &right, 90);
	nodeInsetail(&left, &right, 10);
	nodeInsetail(&left, &right, 40);
	nodeInsetail(&left, &right, 110);
	nodeInsetail(&left, &right, 60);
	nodeInsetail(&left, &right, 95);
	nodeInsetail(&left, &right, 23);

	cout<<"Doubly linked list on printing"
		" from left to right\n";
	printList(left);

	return 0;
}
