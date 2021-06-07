
#include <bits/stdc++.h>
using namespace std;

int subset(int ar[], int n)
{

	int res = 0;

	
	sort(ar, ar + n);

	for (int i = 0; i < n; i++) {
		int count = 1;

		for (; i < n - 1; i++) {
			if (ar[i] == ar[i + 1])
				count++;
			else
				break;
		}

		res = max(res, count);
	}

	return res;
}

int main()
{
	int arr[] = { 5, 6, 9, 3, 4, 3, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << subset(arr, n);
	return 0;
}
