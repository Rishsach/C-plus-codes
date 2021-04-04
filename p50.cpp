
#include <bits/stdc++.h>
using namespace std;

struct Graph {
	int V;
	set<int, greater<int> >* adjList;
};

Graph* createGraph(int V)
{
	Graph* graph = new Graph;
	graph->V = V;
	graph->adjList = new set<int, greater<int> >[V];

	return graph;
}

void addEdge(Graph* graph, int src, int dest)
{
	
	graph->adjList[src].insert(dest);


	graph->adjList[dest].insert(src);
}

void printGraph(Graph* graph)
{
	for (int i = 0; i < graph->V; ++i) {
		set<int, greater<int> > lst = graph->adjList[i];
		cout << endl << "Adjacency list of vertex "
			<< i << endl;

		for (auto itr = lst.begin(); itr != lst.end(); ++itr)
			cout << *itr << " ";
		cout << endl;
	}
}


void searchEdge(Graph* graph, int src, int dest)
{
	auto itr = graph->adjList[src].find(dest);
	if (itr == graph->adjList[src].end())
		cout << endl << "Edge from " << src
			<< " to " << dest << " not found."
			<< endl;
	else
		cout << endl << "Edge from " << src
			<< " to " << dest << " found."
			<< endl;
}
int main()
{
	
	int V = 5;
	struct Graph* graph = createGraph(V);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);

	printGraph(graph);

	searchEdge(graph, 2, 1);
	searchEdge(graph, 0, 3);

	return 0;
}