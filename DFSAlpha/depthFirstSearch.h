//
// Created by Greg LaKomski on 2019-04-07.
//

#ifndef DEPTHFIRSTSEARCHGRAPH_DEPTHFIRSTSEARCH_H
#define DEPTHFIRSTSEARCHGRAPH_DEPTHFIRSTSEARCH_H

/** @authors  https://www.techiedelight.com/depth-first-search/
 * @authors modified by greg lakomski 3/31/2019
*/


#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>


// data structure to store graph edges
struct Edge {
  int src, dest, weight;
};

/** @brief  class to represent a graph object
 *
 *
/// This is the place where you create the adjacency list
/// Once you add all the pairs to the vectors, you must SORT each vector to that the
/// adjacent vertices are sorted by weight!

 */

class Graph
{
 public:
  // construct a vector of vectors to represent an adjacency list
  std::vector<std::vector<std::pair<int,int> > >adjList;

  // Graph Constructor
  Graph(std::vector<Edge> const &edges, int N)
  {
    // resize the vector to N elements of type vector<int>
    adjList.resize(N);

    // add edges (u,weight,v) to the undirected graph  add pair (weight, v)
    for (auto &edge: edges) {
      /** Note that this is for undirected graph so both ways */
      // create adjacency list
      adjList[edge.src].push_back(std::make_pair(edge.dest, edge.weight));
      adjList[edge.dest].push_back(std::make_pair(edge.src, edge.weight));
    }

    /** Contains a commented out  print out the graph routine that is commented out
     * You must sort the adjacency list vectors by weight!!*/
    
      int printu = 0;

      for (auto &list : adjList) {
        std::sort(list.begin(), list.end(),
        [](const std::pair<int, int> &a, const std::pair<int, int> &b ) {
          return a.second > b.second;
        });
      }

//      for (auto it : adjList) {
//        std::for_each(it.begin(), it.end(),
//        [printu](std::pair<int,int> p) {std::cout<<printu<<" "<< p.first <<" "<<p.second<< std::endl; }
//        );
//        printu ++;
//      }

  }
};

// Perform iterative DFS on graph g starting from vertex v
void iterativeDFS(Graph const &graph, int v, int N, std::vector<bool> & discovered) {
  // create a stack used to do iterative DFS
  std::stack<int> stack;

  // push the source node into stack
  stack.push(v);


  // run till stack is not empty
  while (!stack.empty()) {
    // Pop a vertex from stack
    // print pop char+65
    int v = stack.top();
    stack.pop();
    printf("pop %c\n", v + 65);

    // if vertex discovered, ignore
    if (discovered[v]) continue;

    // discover
    discovered[v] = true;
    printf("discover %c\n", v + 65);

    // for all edges in popped vertex
    //  if not discovered,
    //    push to stack in ascending order
    //    print push char + 65
    for (auto it = graph.adjList[v].begin(); it != graph.adjList[v].end(); ++it) {
      int newV = it->first;

      if(!discovered[newV]) {
        stack.push(newV);
        printf("push %c\n", newV + 65);
      }
    }
  }
}


#endif //DEPTHFIRSTSEARCHGRAPH_DEPTHFIRSTSEARCH_H
