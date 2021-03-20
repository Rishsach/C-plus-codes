
#include <iostream>
using namespace std;
int findMaximum(int arr[], int low, int high) 
{ 
	int max = arr[low]; 
	int i; 
	for (i = low + 1; i <= high; i++) 
	{ 
		if (arr[i] > max) 
			max = arr[i]; 
		
		else
			break; 
	} 
	return max; 
} 
int main() 
{ 
	int arr[] = {1, 30, 40, 50, 60, 70, 23, 20}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "The maximum element is " << findMaximum(arr, 0, n-1); 
	return 0; 
} 

