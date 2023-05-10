// A simple representation of graph using STL
#include <iostream>
using namespace std;

// A utility function to add an edge in an
// undirected graph.
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

// A utility function to print the adjacency list
// representation of graph
void printGraph(vector<int> adj[], int V)
{
	for (int v = 0; v < V; ++v) {
		cout << "\n Adjacency list of vertex " << v
			<< "\n head ";
		for (auto x : adj[v])
			cout << "-> " << x;
		cout << endl;
	}
}

int main()
{
	int V = 5;
	vector<int> adj[V];
	addEdge(adj, 0, 1);
	addEdge(adj, 1, 3);
	addEdge(adj, 3, 2);
	addEdge(adj, 3, 4);
	addEdge(adj, 4, 5);
	addEdge(adj, 4, 0);
	addEdge(adj, 1, 2);
	printGraph(adj, V);
	return 0;
}
