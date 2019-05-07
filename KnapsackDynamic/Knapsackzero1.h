//
// Created by Greg LaKomski on 2019-04-16.
//

#ifndef KNAPSACK1_KNAPSACKZERO1_H
#define KNAPSACK1_KNAPSACKZERO1_H

// A Dynamic Programming based solution for 0-1 Knapsack problem
#include <iostream>
#include<vector>
#include<algorithm>



// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, std::vector<int> wt, std::vector<int> val, std::vector<std::vector<int>> & B, int num)
{
 
  auto  i = 0;
  auto maxW = 0;  // this is for as we work across the top row of B matrix
  

  // Build table B[][] in bottom up manner
  for (i = 0; i <= num; i++)
  {
    for (maxW = 0; maxW <= W; maxW++)
    {
      if (i==0 || maxW==0)
        B[i][maxW] = 0;
      else if (wt[i - 1] <= maxW)
        B[i][maxW] = std::max(val[i-1] + B[i-1][maxW-wt[i-1]],  B[i-1][maxW]);
      else
        B[i][maxW] = B[i-1][maxW];
    }
  }

  return B[num][W];
}

void printsack(std::vector<std::vector<int>> & B, std::vector<int> wt, int num, int W){

  int i = num;
  int k = W;

  std::cout<<std::endl;

  while (i > 0 && k > 0) {
    if (B[i][k] != B[i-1][k]) {
      printf("%d ", i);
      i--;
      k = wt[i];
    }
    else {
      i--;
    }
  }
}

#endif //KNAPSACK1_KNAPSACKZERO1_H