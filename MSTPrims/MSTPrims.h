

/*
 *1) Initialize weights of all vertices as infinite and
   parent of every vertex as -1.

2) Create an empty priority_queue pq.  Every item
   of pq is a pair (weight, vertex). Weight (or
   key) is used used as first item  of pair
   as first item is by default used to compare
   two pairs.

3) Initialize all vertices as not part of MST yet.
   We use boolean array inMST[] for this purpose.
   This array is required to make sure that an already
   considered vertex is not included in pq again. This
   is where Prim's implementation differs from Dijkstra.
   In Dijkstra's algorithm, we didn't need this array as
   distances always increase. We require this array here
   because weight value of a processed vertex may decrease
   if not checked.

4) Insert source vertex into pq and make its weight as 0.

5) While either pq doesn't become empty
    a) Extract minimum weight vertex from pq.
       Let the extracted vertex be u.

    b) Include u in MST using inMST[u] = true.

    c) Loop through all adjacent of u and do
       following for every vertex v.

           // If weight of edge (u,v) is smaller than
           // weight of v and v is not already in MST
           If inMST[v] = false && weight[v] > weight(u, v)

               (i) Update weight of v, i.e., do
                     weight[v] = weight(u, v)
               (ii) Insert v into the pq
               (iv) parent[v] = u

6) Print MST edges using parent array.
 */


// STL implementation of Prim's algorithm for MST
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>


# define INF 0x3f3f3f3f

// This class represents a directed graph using
// adjacency list representation
class MSTPrims
{
 private:

  int V;    // No. of vertices

  // In a weighted graph, we need to store vertex
  // and weight pair for every edge
  // vector holds linked lists for each vertex
  std::vector<std::list<std::pair<int,int>>> adj;

  // create vector with correct number of lists
  std::vector<std::list<std::pair<int,int>>> createAdjList(int V);


 public:
  MSTPrims(int V);  // Constructor

  // function to add an edge to graph
  void addEdge(int u, int v, int w);

  // Print MST using Prim's algorithm
  void primMST();
  ;
};


// Allocates memory for adjacency list
MSTPrims::MSTPrims(int V) {

  this->V = V;

  this->adj = createAdjList(V);

}


std::vector<std::list<std::pair<int,int>>> MSTPrims::createAdjList(int V){

  std::list<std::pair<int,int>> tmp ;

  std::vector<std::list<std::pair<int,int>>> adj (V,tmp) ;

  return adj;

}

// add edge to the adjacency list
void MSTPrims::addEdge(int u, int v, int w)
{

--------------------  code  ----------------------
}

// Prints shortest paths from src to all other vertices
void MSTPrims::primMST()
{
  // Create a priority queue to store vertices that
  // are being preinMST. This is weird syntax in C++.
  // Refer below link for details of this syntax
  // http://geeksquiz.com/implement-min-heap-using-stl/
  // greater is in
  std::priority_queue< std::pair<int, int>, std::vector <std::pair<int, int>> , std::greater<std::pair<int, int>> > pq;

  auto src = 0; // Taking vertex 0 as source

  // Create a vector for weights and initialize all
  // weights as infinite (INF)
  std::vector<int> weight(V, INF);

  // To store parent array which in turn store MST - vector int init to -1
  std::vector<int> parent(V, -1);

  // To keep track of vertices included in MST - vector bool init to false
  std::vector<bool> inMST(V, false);

  // Insert source itself in priority queue and initialize
  // its weight as 0.
  pq.push(std::make_pair(0, src));
  weight[src] = 0;

  /* Looping till priority queue becomes empty */
  while (!pq.empty())
  {
    // The first vertex in pair is the minimum weight
    // vertex, extract it from priority queue.
    // vertex label is stored in second of pair (it
    // has to be done this way to keep the vertices
    // sorted weight (weight must be first item
    // in pair)


    ------------------------ code --------------------

  }

  // Print edges of MST using parent array
  // Note: mutable to deal with counter assignment
  // Note: ++parent to skip the first entry in parent
  auto counter = 1;
  printf("u   v\n");
  for_each(++parent.begin(),parent.end(),[counter] (int y) mutable {

    printf("%d - %d\n", y, counter);
    counter ++;
  });

}
