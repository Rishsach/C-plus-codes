
#include <bits/stdc++.h>
using namespace std;



struct Node {
	int data;
	Node* next;
	Node(int x)
	{
		data = x;
		next = NULL;
	}
};

struct Node* push(struct Node* last, int data)
{
	if (last == NULL) {
		struct Node* temp
			= (struct Node*)malloc(sizeof(struct Node));

		
		temp->data = data;
		last = temp;
		
		temp->next = last;

		return last;
	}

	
	struct Node* temp
		= (struct Node*)malloc(sizeof(struct Node));

	
	temp->data = data;

	
	temp->next = last->next;
	last->next = temp;

	return last;
}



int countNodes(Node* head)
{
	Node* temp = head;
	int result = 0;
	if (head != NULL) {
		do {
			temp = temp->next;
			result++;
		} while (temp != head);
	}

	return result;
}

int main()
{
	Node* head = NULL;
	head = push(head, 12);
	head = push(head, 56);
	head = push(head, 2);
	head = push(head, 11);
	cout << countNodes(head);
	return 0;
}


