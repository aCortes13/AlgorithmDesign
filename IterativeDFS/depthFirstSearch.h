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
    for (auto &edge: edges)
    {
      /** Note that this is for undirected graph so both ways */
      // create adjacency list
     
     //******************* your code to populate adj list  ******************

    }

    /** Contains a commented out  print out the graph routine that is commented out
     * You must sort the adjacency list vectors by weight!!*/
    
      int printu = 0;
      //*********************** sort the vectors by weight ***********************
        
    //std::for_each ((*it).begin(), (*it).end(), [printu](std::pair<int,int> p) {std::cout<<printu<<" "<< p.first <<" "<<p.second<< std::endl;});
    // printu ++;
    // }

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


  // ************************  your code for DFS ******************
  // *************** Make sure it prinnts out pop,push, discover  in appropriate places



  }
}


#endif //DEPTHFIRSTSEARCHGRAPH_DEPTHFIRSTSEARCH_H
