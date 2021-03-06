
#include <iostream>
using namespace std;

int countRefill(int N, int K, int M, int compulsory[])
{
	int count = 0;
	int i = 0;
	int distCovered = 0;

	while (distCovered < N) {
	
		if (i < M && compulsory[i] <= (distCovered + K)) {
			distCovered = compulsory[i];

			
			i++;
		}

		else
			distCovered += K;

		if (distCovered < N)
			count++;
	}

	return count;
}
int main()
{
	int N = 10;
	int K = 2;
	int M = 3;
	int compulsory[] = { 6, 7, 8 };

	cout << countRefill(N, K, M, compulsory) << endl;
	return 0;
}
