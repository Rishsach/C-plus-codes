
#include <bits/stdc++.h>
using namespace std;

void printMaxOfMin(int arr[], int n)
{
	for (int k = 1; k <= n; k++) {
		
		int maxOfMin = INT_MIN;

		for (int i = 0; i <= n - k; i++) {
	
			int min = arr[i];
			for (int j = 1; j < k; j++) {
				if (arr[i + j] < min)
					min = arr[i + j];
			}

			if (min > maxOfMin)
				maxOfMin = min;
		}

		cout << maxOfMin << " ";
	}
}

int main()
{
	int arr[] = { 10, 20, 30, 50, 10, 70, 30 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printMaxOfMin(arr, n);
	return 0;
}
