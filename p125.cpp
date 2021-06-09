/*
* C++ program to count all paths from a source to a
* destination.
* https://www.geeksforgeeks.org/count-possible-paths-two-vertices/
* Note that the original example has been refactored.
*/
#include <cassert>
#include <list>
using namespace std;

class Graph {
public:
	
	Graph(int vertices);

	void add_edge(int src, int dst);

	int count_paths(int src, int dst);

private:
	int m_vertices;
	list<int>* m_neighbours;
	void path_counter(int src, int dst, int& path_count);
};

Graph::Graph(int vertices)
{
	m_vertices = vertices;
	
	m_neighbours = new list<int>[vertices];
}

void Graph::add_edge(int src, int dst)
{
	m_neighbours[src].push_back(dst);
}

int Graph::count_paths(int src, int dst)
{
	int path_count = 0;
	path_counter(src, dst, path_count);
	return path_count;
}


void Graph::path_counter(int src, int dst, int& path_count)
{

	if (src == dst) {
		path_count++;
	}
	
	else {
		for (auto neighbour : m_neighbours[src]) {
			path_counter(neighbour, dst, path_count);
		}
	}
}

int main()
{
	Graph g(5);
	g.add_edge(0, 1);
	g.add_edge(0, 2);
	g.add_edge(0, 3);
	g.add_edge(1, 3);
	g.add_edge(1, 4);
	g.add_edge(2, 3);
	g.add_edge(2, 4);

	assert(3 == g.count_paths(0, 3));

	return 0;
}
