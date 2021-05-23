#include<bits/stdc++.h>
using namespace std;

void leftSmaller(int arr[], int n, int SE[])
{
	stack<int>S;

	for (int i=0; i<n; i++)
	{
		while (!S.empty() && S.top() >= arr[i])
			S.pop();

		if (!S.empty())
			SE[i] = S.top();

		else
			SE[i] = 0;

		S.push(arr[i]);
	}
}

int findMaxDiff(int arr[], int n)
{
	int LS[n]; 

	leftSmaller(arr, n, LS);

	int RRS[n]; 
	reverse(arr, arr + n);
	leftSmaller(arr, n, RRS);

	int result = -1;
	for (int i=0 ; i< n ; i++)
		result = max(result, abs(LS[i] - RRS[n-1-i]));

	return result;
}
int main()
{
	int arr[] = {2, 4, 8, 7, 7, 9, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Maximum diff : "
		<< findMaxDiff(arr, n) << endl;
	return 0;
}
