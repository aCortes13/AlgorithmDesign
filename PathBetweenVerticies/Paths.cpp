#include <iostream>
#include <vector>
#include <list>
#include <queue>

struct Edge {
    int src, dest;  // integer number of vertice as loaded
};

struct Graph {
   std::vector<std::list<int>> adj_list;
   Graph (const std::vector<Edge>& edge_set, int n) {
    adj_list.resize(n);

    for (auto& e: edge_set)
      adj_list[e.src].push_back(e.dest);
  }
};

class Solution {
public:

    // Constructor - create new graph and initialize visited to 0
    Solution (const std::vector<Edge>& edge_set, int n) {
       
       ------------------ code --------------------
    }

    // uses BFS to determine whether connected
    bool isConnected (const int src, const int dest) {
       
       ---------------------- code ----------------------
        return retval;
    }

private:
  Graph* myGraph;

  std::vector<bool> visited;

  std::vector<int> path;
  
  // BFS  - if connected returns true - else false
  bool BFS (const int src, const int dest) {
     
     --------------- code ----------------------
     
  }     
};