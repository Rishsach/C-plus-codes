
#include <bits/stdc++.h>
using namespace std;

int smallestKFreq(int a[], int n, int k)
{
	unordered_map<int, int> m;

	for (int i = 0; i < n; i++)
		m[a[i]]++;

	int res = INT_MAX;
	for (auto it = m.begin(); it != m.end(); ++it)
		if (it->second == k)
		res = min(res, it->first);

	return (res != INT_MAX)? res : -1;
}
int main()
{
	int arr[] = { 2, 2, 1, 3, 1 };
	int k = 2;
	int n = sizeof(arr) / (sizeof(arr[0]));
	cout << smallestKFreq(arr, n, k);
	return 0;
}
