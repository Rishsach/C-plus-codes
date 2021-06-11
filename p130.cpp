#include <bits/stdc++.h>
using namespace std;



class Solution {
public:

	int getMinDiff(int arr[], int n, int k)
	{
		sort(arr, arr + n);
		int minEle, maxEle;
		int result = arr[n - 1] - arr[0];

		for (int i = 1; i <= n - 1; i++) {
		maxEle = max(arr[i - 1] + k, arr[n - 1] - k);
		minEle = min(arr[0] + k, arr[i] - k);

		}
		return result;
	}
};

int main()
{
	int t=1;
	
	while (t--) {
		int k = 6;
	int n=3;
		int arr[n]={1, 15, 10};
	
		
		Solution ob;
		auto ans = ob.getMinDiff(arr, n, k);
		cout << ans << "\n";
	}
	return 0;
}
