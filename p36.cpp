
#include <iostream>
using namespace std;

void nextGreatest(int arr[], int size)
{
	
	int max_from_right = arr[size-1];
	

	arr[size-1] = -1;
	
	for(int i = size-2; i >= 0; i--)
	{
		int temp = arr[i];
	
		arr[i] = max_from_right;
	
		if(max_from_right < temp)
		max_from_right = temp;
	}
}
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = {16, 17, 4, 3, 5, 2};
	int size = sizeof(arr)/sizeof(arr[0]);
	nextGreatest (arr, size);
	cout << "The modified array is: \n";
	printArray (arr, size);
	return (0);
}

