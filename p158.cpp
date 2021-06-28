
#include<bits/stdc++.h>
using namespace std;


int minEdgeBFS(vector <int> edges[], int u,
							int v, int n)
{
	
	vector<bool> visited(n, 0);

	
	vector<int> distance(n, 0);

	
	queue <int> Q;
	distance[u] = 0;

	Q.push(u);
	visited[u] = true;
	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();

		for (int i=0; i<edges[x].size(); i++)
		{
			if (visited[edges[x][i]])
				continue;

			
			distance[edges[x][i]] = distance[x] + 1;
			Q.push(edges[x][i]);
			visited[edges[x][i]] = 1;
		}
	}
	return distance[v];
}


void addEdge(vector <int> edges[], int u, int v)
{
edges[u].push_back(v);
edges[v].push_back(u);
}

int main()
{
	
	int n = 9;
	vector <int> edges[9];
	addEdge(edges, 0, 1);
	addEdge(edges, 0, 7);
	addEdge(edges, 1, 7);
	addEdge(edges, 1, 2);
	addEdge(edges, 2, 3);
	addEdge(edges, 2, 5);
	addEdge(edges, 2, 8);
	addEdge(edges, 3, 4);
	addEdge(edges, 3, 5);
	addEdge(edges, 4, 5);
	addEdge(edges, 5, 6);
	addEdge(edges, 6, 7);
	addEdge(edges, 7, 8);
	int u = 0;
	int v = 5;
	cout << minEdgeBFS(edges, u, v, n);
	return 0;
}
