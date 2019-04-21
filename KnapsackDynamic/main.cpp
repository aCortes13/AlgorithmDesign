// A Dynamic Programming based solution for 0-1 Knapsack problem
#include <iostream>
#include<vector>
#include<algorithm>
#include "Knapsackzero1.h"

int main()
{std::vector<int> val { 60, 100, 120 };
  std::vector<int> wt  { 10, 20, 30 };
  int W = 60;

  auto num = wt.size();

  std::vector<std::vector<int>> B (num + 1,std::vector<int> (W + 1));  // B is maximum total value table

  std::cout << knapSack(W, wt, val, B , num);

  printsack(B,wt,num,W);
  return 0;
}