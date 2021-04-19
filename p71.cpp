
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* right, *down;
};

Node* construct(int arr[][3], int i, int j,
							int m, int n)
{
	
	if (i > n - 1 || j > m - 1)
		return NULL;

	Node* temp = new Node();
	temp->data = arr[i][j];
	temp->right = construct(arr, i, j + 1, m, n);
	temp->down = construct(arr, i + 1, j, m, n);
	return temp;
}

void display(Node* head)
{
	
	Node* Rp;


	Node* Dp = head;

	while (Dp) {
		Rp = Dp;

		while (Rp) {
			cout << Rp->data << " ";
			Rp = Rp->right;
		}
		cout << "\n";
		Dp = Dp->down;
	}
}
int main()
{
	int arr[][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};

	int m = 3, n = 3;
	Node* head = construct(arr, 0, 0, m, n);
	display(head);
	return 0;
}
