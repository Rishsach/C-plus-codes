#include <bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k)
{
	if (n == 1)
	return 0;

	sort(arr, arr+n);

	int ans = arr[n-1] - arr[0];

	int small = arr[0] + k;
	int big = arr[n-1] - k;
	if (small > big)
	swap(small, big);

	for (int i = 1; i < n-1; i ++)
	{
		int subtract = arr[i] - k;
		int add = arr[i] + k;

		if (subtract >= small || add <= big)
			continue;

		if (big - subtract <= add - small)
			small = subtract;
		else
			big = add;
	}

	return min(ans, big - small);
}

int main()
{
	int arr[] = {4, 6};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 10;
	cout << "\nMaximum difference is "
		<< getMinDiff(arr, n, k);
	return 0;
}
