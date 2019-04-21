#include <cstdio>
#include <iostream>
#include <limits>
#include "MatrixChain.h"
#include <vector>
#include <string>
int main()
{

  auto N = 4; // Number of matrices


  std::vector<int> arr (N+1);


  /**
   * @brief the matrices are defined as d0 x d1, d1 X d2, d2 X d3, ....
   */
  arr = {10,100,20,5,80}; // vector of matrix dimensions d0,d2,d2,d3

  std::cout<< "Minimum number of multiplications is " << MatrixChainMultiplication(arr) << std::endl;

  return 0;
}