

#include <bits/stdc++.h>
using namespace std;

struct Node {
	struct Node *left, *right;
	int key;
};


Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}


Node* insertNode(Node* node, int key)
{
	if (node == NULL)
		return newNode(key);

	
	if (key < node->key)
		node->left = insertNode(
			node->left, key);

	else if (key > node->key)
		node->right = insertNode(
			node->right, key);

	
	return node;
}


void getIntermediateNodes(
	Node* root, vector<int>& interNodes,
	int node1, int node2)
{

	if (root == NULL)
		return;

	
	getIntermediateNodes(root->left,
						interNodes,
						node1, node2);

	
	if (root->key <= node2
		and root->key >= node1) {
		interNodes.push_back(root->key);
	}

	
	getIntermediateNodes(root->right,
						interNodes,
						node1, node2);
}


float findMedian(Node* root, int node1,
				int node2)
{

	vector<int> interNodes;

	getIntermediateNodes(root, interNodes,
						node1, node2);

	
	int nSize = interNodes.size();

	return (nSize % 2 == 1)
			? (float)interNodes[nSize / 2]
			: (float)(interNodes[(nSize - 1) / 2]
						+ interNodes[nSize / 2])
					/ 2;
}


int main()
{
	
	struct Node* root = NULL;
	root = insertNode(root, 8);
	insertNode(root, 3);
	insertNode(root, 1);
	insertNode(root, 6);
	insertNode(root, 4);
	insertNode(root, 11);
	insertNode(root, 15);

	cout << findMedian(root, 3, 11);

	return 0;
}
