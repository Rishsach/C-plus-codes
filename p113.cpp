
#include <bits/stdc++.h>
using namespace std;


int minproduct(int a[], int b[], int n, int k)
{
	int diff = 0, res = 0;
	int temp;
	for (int i = 0; i < n; i++) {

		int pro = a[i] * b[i];
		res = res + pro;

		
		if (pro < 0 && b[i] < 0)
			temp = (a[i] + 2 * k) * b[i];

	
		else if (pro < 0 && a[i] < 0)
			temp = (a[i] - 2 * k) * b[i];

	
		else if (pro > 0 && a[i] < 0)
			temp = (a[i] + 2 * k) * b[i];
		else if (pro > 0 && a[i] > 0)
			temp = (a[i] - 2 * k) * b[i];

		
		int d = abs(pro - temp);
		if (d > diff)
			diff = d;	
	}

	return res - diff;
}
int main()
{
	int a[] = { 2, 3, 4, 5, 4 };
	int b[] = { 3, 4, 2, 3, 2 };
	int n = 5, k = 3;
	cout << minproduct(a, b, n, k)
		<< endl;
	return 0;
}
