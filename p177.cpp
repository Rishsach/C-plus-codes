

#include <bits/stdc++.h>
using namespace std;

int MaximumSum(vector<vector<int> >& arr, int n)
{

	int ans = 0;

	for (int i = 0; i < n; i++) {
		int x = 0, y = i, sum = 0;
		for (int j = i; j < n; j++) {
			sum += arr[x++][y++];
		}
		if (sum > ans)
			ans = sum;
	}

	for (int i = 1; i < n; i++) {

		int x = i, y = 0, sum = 0;

		for (int j = i; j < n; j++) {

			sum += arr[x++][y++];
		}
		if (sum > ans)
			ans = sum;
	}

	return ans;
}

int main()
{


	vector<vector<int> > arr;
	arr = { { 1, 2, 3 },
			{ 3, 5, 10 },
			{ 1, 3, 5 } };

	int n = arr.size();

	cout << MaximumSum(arr, n);

	return 0;
}
