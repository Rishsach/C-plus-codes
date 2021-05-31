#include <bits/stdc++.h>
using namespace std;

void optimum_sequence_jobs(vector<int>& V, double P)
{
	int j = 1, N = V.size() - 1;
	double result = 0;

	priority_queue<int, vector<int>, greater<int> > Queue;

	for (int i = 1; i <= N; i++)
		Queue.push(V[i]);

	while (!Queue.empty()) {


		cout << Queue.top() << " ";

		V[j++] = Queue.top();
		Queue.pop();
	}
	for (int i = N; i >= 1; i--)
		result += pow((1 - P), N - i) * V[i];

	cout << endl << result << endl;
}

int main()
{

	vector<int> V{ -1, 3, 5, 4, 1, 2, 7, 6, 8, 9, 10 };


	double P = 0.10;

	optimum_sequence_jobs(V, P);

	return 0;
}
