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
      myGraph = new Graph(edge_set, n);
      visited = std::vector<bool>(n, 0);
    }

    // uses BFS to determine whether connected
    bool isConnected (const int src, const int dest) {
      return BFS(src, dest);
    }

private:
  Graph* myGraph;

  std::vector<bool> visited;

  std::vector<int> path;
  // BFS  - if connected returns true - else false
  bool BFS (const int src, const int dest) {
    int popped;

    visited[src] = true;
    path.push_back(src);

    while (!path.empty()) {
      popped = path.front();
      path.erase(path.begin());

      if (popped == dest)
        return true;

      for (auto i : myGraph->adj_list[popped]) {
        if (!visited[i])
          path.push_back(i);
          visited[i] = true;

        if (visited[dest])
          return true;
      }
    }
    return false;
  }
};