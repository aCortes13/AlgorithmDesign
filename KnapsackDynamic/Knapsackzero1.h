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
    ----code ------
  }

  return B[num][W];
}

void printsack(std::vector<std::vector<int>> & B, std::vector<int> wt, int num, int W){

  int i = num;
  int k = W;

  std::cout<<std::endl;
  
----- code --------
}

#endif //KNAPSACK1_KNAPSACKZERO1_H