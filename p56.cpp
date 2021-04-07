#include <bits/stdc++.h>
using namespace std;


class node
{
	public:
	int data;
	node* left;
	node* right;
};

bool isCompleteBT(node* root)
{
	if (root == NULL)
		return true;
	queue<node *> q;
	q.push(root);
	bool flag = false;

	while(!q.empty())
	{
		node *temp =q.front();
		q.pop();

		
		if(temp->left)
		{
		
		if (flag == true)
			return false;

		q.push(temp->left);
		}
		else 
		flag = true;
		if(temp->right)
		{
		if(flag == true)
			return false;

		q.push(temp->right);
		}
		else 
		flag = true;
	}
	return true;
}

node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return(Node);
}
int main()
{
	

	node *root = newNode(1);
	root->left	 = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);

	if ( isCompleteBT(root) == true )
		cout << "Complete Binary Tree";
	else
		cout << "NOT Complete Binary Tree";

	return 0;
}
