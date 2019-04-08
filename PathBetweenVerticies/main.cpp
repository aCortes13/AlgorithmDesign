#include <iostream>
#include <vector>
#include "Paths.cpp"


int main() {
    std::vector<Edge> edges { {0, 3}, {1, 0}, {1, 2}, {1, 4}, {2, 7},
                              {3, 4}, {3, 5}, {4, 3}, {4, 6}, {5, 6}, {6, 7} };
    int SIZE = 8, src = 0, dest = 7;

    Solution mySolution(edges, SIZE);
    if (mySolution.isConnected(src, dest))
        std::cout << src << " has a path to " << dest << std::endl;

    return 0;
}