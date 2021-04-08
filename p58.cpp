#include <iostream>
#include <vector>
using namespace std;

void dfs(int parent, int ans[], vector<int> connectchars[])
{
	
	ans[parent] = 1;

	for (int i = 0; i < connectchars[parent].size(); i++) {
		if (!ans[connectchars[parent][i]])
			dfs(connectchars[parent][i], ans, connectchars);
	}
}

void printBinaryPalindrome(int n, int k)
{
	int arr[n], ans[n] = { 0 };

	vector<int> connectchars[k];

	for (int i = 0; i < n; i++)
		arr[i] = i % k;

	
	for (int i = 0; i < n / 2; i++) {
		connectchars[arr[i]].push_back(arr[n - i - 1]);
		connectchars[arr[n - i - 1]].push_back(arr[i]);
	}

	dfs(0, ans, connectchars);

	for (int i = 0; i < n; i++)
		cout << ans[arr[i]];
}

int main()
{
	int n = 10, k = 4;
	printBinaryPalindrome(n, k);
	return 0;
}
