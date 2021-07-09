
#include <bits/stdc++.h>

struct Node {
	int data;
	Node* next;
};
Node* newNode(int data)
{
	Node* new_node = new Node;
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

Node* addOne(Node *head)
	{
		Node* ln = head;
		if(head->next == NULL){
			head->data+=1;
			return head;
		}
		Node *t = head;
		int prev;
		while(t -> next){
			if(t->data != 9){
				ln = t;
			}
			t = t->next;
			
		}
		if(t->data==9 && ln != NULL){
			t = ln;
			t -> data += 1;
			t = t->next;
			while(t){
			t->data = 0;
			t = t->next;
			}
		}else{
			t->data+=1;
		}
		return head;
	}

void printList(Node* node)
{
	while (node != NULL) {
		printf("%d", node->data);
		node = node->next;
	}
	printf("\n");
}

int main(void)
{
	Node* head = newNode(1);
	head->next = newNode(9);
	head->next->next = newNode(9);
	head->next->next->next = newNode(9);

	printf("List is ");
	printList(head);

	head = addOne(head);

	printf("\nResultant list is ");
	printList(head);

	return 0;
}

