

#include <bits/stdc++.h>
using namespace std;

void longestSubsequence(int* arr, int N)
{
	int dp[N][N + 1];

	memset(dp, -1, sizeof dp);

	for (int i = 0; i < N; ++i) {
		dp[i][0] = 0;
	}

	dp[0][1] = (arr[0] >= 0 ? arr[0] : -1);

	for (int i = 1; i < N; ++i) {

		for (int j = 1;
			j <= (i + 1); ++j) {

			if (dp[i - 1][j] != -1) {
				dp[i][j] = max(
					dp[i][j], dp[i - 1][j]);
			}

			if (dp[i - 1][j - 1] >= 0
				&& dp[i - 1][j - 1]
						+ arr[i]
					>= 0) {

				dp[i][j] = max(
					dp[i][j],
					dp[i - 1][j - 1]
						+ arr[i]);
			}
		}
	}

	int ans = 0;

	for (int j = 0; j <= N; ++j) {
		if (dp[N - 1][j] >= 0) {
			ans = j;
		}
	}

	cout << ans << endl;
}
int main()
{
	int arr[] = { 4, -4, 1, -3, 1, -3 };
	int N = sizeof arr / sizeof arr[0];
	longestSubsequence(arr, N);

	return 0;
}
