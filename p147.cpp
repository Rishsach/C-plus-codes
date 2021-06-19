
#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
	int V; 
	list<int> *adj;

	
	vector<int> degree;

	Graph(int V);		
	void addEdge(int v, int w); 
	vector<int> rootForMinimumHeight();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
	for (int i = 0; i < V; i++)
		degree.push_back(0);
}
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); 
	adj[w].push_back(v); 
	degree[v]++;		 
	degree[w]++;		 
}

vector<int> Graph::rootForMinimumHeight()
{
	queue<int> q;

	
	for (int i = 0; i < V; i++)
		if (degree[i] == 1)
			q.push(i);

	
	while (V > 2)
	{
		int popEle = q.size();
		V -= popEle;	 
		
		for (int i = 0; i < popEle; i++)
		{
			int t = q.front();
			q.pop();

	
			for (auto j = adj[t].begin(); j != adj[t].end(); j++)
			{
				degree[*j]--;
				if (degree[*j] == 1)
					q.push(*j);
			}
		}
	}

	vector<int> res;
	while (!q.empty())
	{
		res.push_back(q.front());
		q.pop();
	}
	return res;
}

int main()
{
	Graph g(6);
	g.addEdge(0, 3);
	g.addEdge(1, 3);
	g.addEdge(2, 3);
	g.addEdge(4, 3);
	g.addEdge(5, 4);


	vector<int> res = g.rootForMinimumHeight();
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
}
