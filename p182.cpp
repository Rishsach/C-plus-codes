
#include <bits/stdc++.h>
using namespace std;

void printGreater(vector<int>& arr)
{
	int n = arr.size();
	for (int i = 0; i < n; i++)
	{
	
		vector<int> result;

		
	
		for (int j = i - 1; j >= 0; j--)
		{
		
			if (arr[j] > arr[i])
			{
				result.push_back(arr[j]);
			}
		}
		cout << arr[i] << ": ";
	
		
		for (int k = 0; k < result.size(); k++)
		{
			cout << result[k] << " ";
		}
		cout << endl;
	}
}


int main()
{
	vector<int> arr{5, 3, 9, 0, 16, 12};
	printGreater(arr);
	return 0;
}
