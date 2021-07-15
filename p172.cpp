
#include<bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node *left;
	node *right;
	node *next;
};

void populateNext(node* p)
{
	
	static node *next = NULL;

	if (p)
	{
		
		populateNext(p->right);
		p->next = next;

	
		next = p;

		
		populateNext(p->left);
	}
}
node* newnode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;
	Node->next = NULL;

	return(Node);
}

int main()
{

	node *root = newnode(10);
	root->left = newnode(8);
	root->right = newnode(12);
	root->left->left = newnode(3);

	populateNext(root);

	node *ptr = root->left->left;
	while(ptr)
	{
		
		cout << "Next of " << ptr->data << " is "
			<< (ptr->next? ptr->next->data: -1)
			<< endl;
		ptr = ptr->next;
	}

	return 0;
}

