#include <iostream>
#include<vector>
using namespace std;

void dfs(int u, int parent, int totalSum,
		vector<int> edge[], int subtree[], int& res)
{
	int sum = subtree[u];

	for (int i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i];
		if (v != parent)
		{
			dfs(v, u, totalSum, edge, subtree, res);
			sum += subtree[v];
		}
	}
	subtree[u] = sum;

	if (u != 0 && abs(totalSum - 2*sum) < res)
		res = abs(totalSum - 2*sum);
}

int getMinSubtreeSumDifference(int vertex[],
					int edges[][2], int N)
{
	int totalSum = 0;
	int subtree[N];

	for (int i = 0; i < N; i++)
	{
		subtree[i] = vertex[i];
		totalSum += vertex[i];
	}
	
	vector<int> edge[N];
	for (int i = 0; i < N - 1; i++)
	{
		edge[edges[i][0]].push_back(edges[i][1]);
		edge[edges[i][1]].push_back(edges[i][0]);
	}

	int res = INT_MAX;

	dfs(0, -1, totalSum, edge, subtree, res);
	return res;
}

int main()
{
	int vertex[] = {4, 2, 1, 6, 3, 5, 2};
	int edges[][2] = {{0, 1}, {0, 2}, {0, 3},
					{2, 4}, {2, 5}, {3, 6}};
	int N = sizeof(vertex) / sizeof(vertex[0]);

	cout << getMinSubtreeSumDifference(vertex, edges, N);
	return 0;
}
