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
  -------------------- CODE ------------------------

  // Parent vector to be able to print the path

  std::vector<int> parent (V,0);


  // Insert source itself in priority queue and initialize
  // its distance as 0.
-------------------- CODE ------------------------

  /* Looping till priority queue becomes empty (or all
  distances are not finalized) */
    -------------------- CODE ------------------------
    // The first vertex in pair is the minimum distance
    // vertex, extract it from priority queue.
    // vertex label is stored in second of pair (it
    // has to be done this way to keep the vertices
    // sorted distance (distance must be first item
    // in pair)

    // extract the vertex u with min distance form source
      -------------------- CODE ------------------------
    // For all adjacent vertices of u.
      -------------------- CODE ------------------------
      // Get vertex label and weight of current adjacent
      // of u.
      -------------------- CODE ------------------------

      // If {u,v} can be relaxed
      -------------------- CODE ------------------------
        // Updating distance of v and update parent vertex
      -------------------- CODE ------------------------
  // Print shortest distance to each vertex from source stored in dist[]
  // Print the path from source to the vertex double space seperated

      -------------------- CODE ------------------------
}
