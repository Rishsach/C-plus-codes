#include <iostream>
using namespace std;

// The function to rearrange an array 
// in-place so that arr[i] becomes arr[arr[i]].
void rearrange(int arr[], int n)
{
	// First step: Increase all values by (arr[arr[i]]%n)*n
	for (int i=0; i < n; i++)
		arr[i] += (arr[arr[i]]%n)*n;
        
	for (int i=0; i<n; i++)
		arr[i] /= n;
}

void printArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}


int main()
{
	int arr[] = {3, 2, 0, 1};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "Given array is \n";
	printArr(arr, n);

	rearrange(arr, n);

	cout << "Modified array is \n";
	printArr(arr, n);
	return 0;
}
