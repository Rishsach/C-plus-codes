
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<int> nextGreaterInLeft(int a[], int n)
{
	vector<int> left_index(MAX, 0);
	stack<int> s;

	for (int i = n - 1; i >= 0; i--) {

		while (!s.empty() && a[i] > a[s.top() - 1]) {
			int r = s.top();
			s.pop();

		
			left_index[r - 1] = i + 1;
		}

		s.push(i + 1);
	}
	return left_index;
}
vector<int> nextGreaterInRight(int a[], int n)
{
	vector<int> right_index(MAX, 0);
	stack<int> s;
	for (int i = 0; i < n; ++i) {

		while (!s.empty() && a[i] > a[s.top() - 1]) {
			int r = s.top();
			s.pop();
			right_index[r - 1] = i + 1;
		}

		s.push(i + 1);
	}
	return right_index;
}
int LRProduct(int arr[], int n)
{
	vector<int> left = nextGreaterInLeft(arr, n);
	vector<int> right = nextGreaterInRight(arr, n);
	int ans = -1;
	for (int i = 1; i <= n; i++) {

		
		ans = max(ans, left[i] * right[i]);
	}

	return ans;
}

int main()
{
	int arr[] = { 5, 4, 3, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[1]);

	cout << LRProduct(arr, n);

	return 0;
}
