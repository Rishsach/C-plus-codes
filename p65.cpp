#include<bits/stdc++.h>
using namespace std;


class node
{
	public:
	int data;
	node *left;
	node *right;
};

void Print(node *root, int k1, int k2)
{
	
	if ( NULL == root )
		return;
	
	if ( k1 < root->data )
		Print(root->left, k1, k2);
	if ( k1 <= root->data && k2 >= root->data )
		cout<<root->data<<" ";
	
	if ( k2 > root->data )
		Print(root->right, k1, k2);
}

node* newNode(int data)
{
	node *temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
}

int main()
{
	node *root = new node();
	int k1 = 10, k2 = 25;
	
	root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	
	Print(root, k1, k2);
	return 0;
}