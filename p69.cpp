
#include <iostream>
using namespace std;

void rearrangeNaive(int arr[], int n)
{

	int temp[n], i;

	for (i = 0; i < n; i++)
		temp[arr[i]] = i;
	for (i = 0; i < n; i++)
		arr[i] = temp[i];
}

void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << ("%d ", arr[i]);
	cout << ("\n");
}

int main()
{
	int arr[] = { 1, 3, 0, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << ("Given array is \n");
	printArray(arr, n);

	rearrangeNaive(arr, n);

	cout << ("Modified array is \n");
	printArray(arr, n);
	return 0;
}