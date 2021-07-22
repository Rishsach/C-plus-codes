
#include <bits/stdc++.h>
using namespace std;

int tin[100], tout[100], depth[100];
int t = 0;
void Add_edge(int parent, int child,
			vector<vector<int> >& adj)
{
	adj[parent].push_back(child);
	adj[child].push_back(parent);
}

void dfs(int node, int parent, vector<vector<int> >& adj,
		vector<vector<int> >& levels, int d)
{
	
	tin[node] = t++;


	levels[d].push_back(tin[node]);
	depth[node] = d;

	for (auto x : adj[node]) {
		if (x != parent)
			dfs(x, node, adj, levels, d + 1);
	}

	/
	tout[node] = t++;
}

void numberOfNodes(int node, int dist,
				vector<vector<int> >& levels)
{
	dist += depth[node];


	int start = lower_bound(levels[dist].begin(),
							levels[dist].end(), tin[node])
				- levels[dist].begin();


	int ed = lower_bound(levels[dist].begin(),
						levels[dist].end(), tout[node])
			- levels[dist].begin();


	cout << ed - start << endl;
}

void numberOfNodesUtil(pair<int, int> Q[], int M, int N)
{

	vector<vector<int> > adj(N + 5), levels(N + 5);

	Add_edge(1, 2, adj);
	Add_edge(1, 3, adj);
	Add_edge(2, 4, adj);
	Add_edge(2, 5, adj);
	Add_edge(2, 6, adj);

	t = 1;

	
	dfs(1, 1, adj, levels, 0);

	
	for (int i = 0; i < M; ++i) {
		numberOfNodes(Q[i].first, Q[i].second, levels);
	}
}

int main()
{

	int N = 6;
	pair<int, int> Q[] = { { 2, 1 }, { 1, 1 } };
	int M = sizeof(Q) / sizeof(Q[0]);


	numberOfNodesUtil(Q, M, N);
}
