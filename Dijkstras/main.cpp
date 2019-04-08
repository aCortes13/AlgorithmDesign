#include <iostream>
#include <vector>
#include <utility>
#include "Dijkstra.h"
int main()
{
  int V = 9;
  std::vector<std::pair<int, int> > adj[V];

  // making above shown graph
  addEdge(adj, 0, 1, 4);
  addEdge(adj, 0, 7, 8);
  addEdge(adj, 1, 2, 8);
  addEdge(adj, 1, 7, 11);
  addEdge(adj, 2, 3, 7);
  addEdge(adj, 2, 8, 2);
  addEdge(adj, 2, 5, 4);
  addEdge(adj, 3, 4, 9);
  addEdge(adj, 3, 5, 14);
  addEdge(adj, 4, 5, 10);
  addEdge(adj, 5, 6, 2);
  addEdge(adj, 6, 7, 1);
  addEdge(adj, 6, 8, 6);
  addEdge(adj, 7, 8, 7);

  shortestPath(adj, V, 0);

  return 0;
}