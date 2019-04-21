//
// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
// Modified by Greg LaKomski  3/25/2019
//


#include<iostream>
#include<cmath>
#include<cstdio>
#include<utility>
#include<vector>
#include<queue>
#include<stack>
#include<cstdint>

// Program to find Dijkstra's shortest path using
// priority_queue in STL and print distance and path


# define INF 0xDEADBEEF

void shortestPath(std::vector<std::pair<int,int> > adj[], int V, int src);

void addEdge(std::vector <std::pair<int, int> > adj[], int u,
             int v, int wt);

// To add an edge
void addEdge(std::vector <std::pair<int, int> > adj[], int u,
             int v, int wt)
{
  adj[u].push_back(std::make_pair(v, wt));
  adj[v].push_back(std::make_pair(u, wt));
}


// Prints shortest paths from src to all other vertices
void shortestPath(std::vector<std::pair<int,int> > adj[], int V, int src)
{
  // Create a priority queue to store vertices that
  // are being preprocessed. This is weird syntax in C++.
  // Refer below link for details of this syntax
  // http://geeksquiz.com/implement-min-heap-using-stl/
  // NOTE: Priority queue of pairs in C++ (Ordered by first)
  std::priority_queue< std::pair<int, int>, std::vector <std::pair<int, int>> , std::greater<std::pair<int, int>> > pq;

  // Create a vector for distances and initialize all
  // distances as infinite (INF)
  std::vector<int> dist (V, INF + 2674818992);

  // Parent vector to be able to print the path
  std::vector<int> parent (V, INF + 2674818992);

  std::vector<bool> visited (V, 0);

  // Insert source itself in priority queue and initialize
  // its distance as 0.
  pq.push(std::make_pair(0, src));
  dist[src] = 0;
  parent[src] = src;

  /* Looping till priority queue becomes empty (or all
  distances are not finalized) */
  while (!pq.empty()) {
    // The first vertex in pair is the minimum distance
    // vertex, extract it from priority queue.
    // vertex label is stored in second of pair (it
    // has to be done this way to keep the vertices
    // sorted distance (distance must be first item
    // in pair)

    // extract the vertex u with min distance form source
    int vertex = pq.top().second;
    visited[vertex] = true;

    pq.pop();
      // For all adjacent vertices of vertex
      for (auto x : adj[vertex]) {
        if (visited[x.first])
          continue;
        // v is next shortest vertex
        // weight is weight to v
        int v = x.first;
        int weight = x.second;

        // If {vertex,v} can be relaxed
        if (dist[v] > dist[vertex] + weight) {
          // Updating distance of v and update parent vertex
          dist[v] = dist[vertex] + weight;
          parent[v] = vertex;
          pq.push(std::make_pair(dist[v], v));
        }
      }
  }
  // Print shortest distance to each vertex from source stored in dist[]
  // Print the path from source to the vertex double space seperated
  std::stack<int> path;

  for (int i = 0; i < V; ++i) {
    printf("Vertex     Distance from Source\n");
    printf("%d                %d  \n", i, dist[i]);

    int next = i;
    path.push(next);
    while (next != src) {
      next = parent[next];
      path.push(next);
    }
    printf("Path from src to vertex\n");

    while (!path.empty()) {
      printf("%d ", path.top());
      path.pop();
    }
    printf("\n");
  }
  printf("END OF OUTPUT");
}
