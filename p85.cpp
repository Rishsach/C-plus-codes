#include <bits/stdc++.h>
using namespace std;

vector<int> no_NGN(int arr[], int n)
{
	vector<int> nxt;

	stack<int> s;

	nxt.push_back(0);

	s.push(n - 1);

	for (int i = n - 2; i >= 0; i--) {
		while (!s.empty() && arr[i] >= arr[s.top()])
			s.pop();

		if (s.empty())
			nxt.push_back(0);
		
		else
		
			nxt.push_back(nxt[n - s.top() - 1] + 1);
		
		s.push(i);
	}
	reverse(nxt.begin(), nxt.end());

	return nxt;
}

int main()
{
	int n = 8;

	int arr[] = { 3, 4, 2, 7, 5, 8, 10, 6 };

	vector<int> nxt = no_NGN(arr, n);
	cout << nxt[3] << endl;
	cout << nxt[6] << endl;

	
	cout << nxt[1] << endl;

	return 0;
}
