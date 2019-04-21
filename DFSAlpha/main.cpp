/** @authors  https://www.techiedelight.com/depth-first-search/
 * @authors modified by greg lakomski 3/31/2019
*/


#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <utility>
#include "depthFirstSearch.h"

// Depth First Search (DFS) Iterative Implementation
int main()
{
  // vector of graph edges as per above diagram
  std::vector<Edge> edges = {

      {0,1,2}, {0,3,15}, {0,8,9}, {1,2,3}, {1,3,5}, {1,4,17},
      {2,5,18}, {2,4,12}, {3,6,6}, {3,4,4}, {4,5,13},{4,6,11},
      {4,7,7},{5,7,14},{6,7,19},{6,8,8},{6,9,10},{7,9,16},{8,9,1}

  };

  // Number of nodes in the graph
#define N 10

  // create a graph from given edges
  Graph graph(edges, N);

  // stores vertex is discovered or not
  std::vector<bool> discovered (N, false);

  // do single DFS
  iterativeDFS(graph, 6, N, discovered);

  return 0;
}