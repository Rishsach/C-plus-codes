
#include <bits/stdc++.h>
#define M 4
using namespace std;


int maximumSum(int a[][M], int n) {

int prev = *max_element(&a[n-1][0],
				&a[n-1][M-1] + 1);

int sum = prev;
for (int i = n - 2; i >= 0; i--) {

	int max_smaller = INT_MIN;
	for (int j = M - 1; j >= 0; j--) {
	if (a[i][j] < prev &&
		a[i][j] > max_smaller)
		max_smaller = a[i][j];
	}

	
	if (max_smaller == INT_MIN)
	return 0;

	prev = max_smaller;
	sum += max_smaller;
}

return sum;
}


int main() {
int arr[][M] = {{1, 7, 3, 4},
				{4, 2, 5, 1},
				{9, 5, 1, 8}};
int n = sizeof(arr) / sizeof(arr[0]);
cout << maximumSum(arr, n);
return 0;
}
