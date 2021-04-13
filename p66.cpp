
#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
};

int height(node* node);

bool isBalanced(node* root)
{
	int lh; 
	int rh;

	if (root == NULL)
		return 1;


	lh = height(root->left);
	rh = height(root->right);

	if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
		return 1;

	return 0;
}
int max(int a, int b)
{
	return (a >= b) ? a : b;
}

int height(node* node)
{
	
	if (node == NULL)
		return 0;

	return 1 + max(height(node->left),
				height(node->right));
}

node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}

int main()
{
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->left->left = newNode(8);

	if (isBalanced(root))
		cout << "Tree is balanced";
	else
		cout << "Tree is not balanced";
	return 0;
}
