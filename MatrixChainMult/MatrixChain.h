//
// HEavily modified  by Greg LaKomski on 2019-04-14.
//

#ifndef MATRIXCHAIN_MATRIXCHAINTEMPLATE_H
#define MATRIXCHAIN_MATRIXCHAINTEMPLATE

#include<stdio.h>
#include<limits.h>
#include <vector>




// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n

int MatrixChainMultiplication(std::vector<int> arr){

  auto n = arr.size();
  std::vector<std::vector<int>> minOps(n,std::vector<int>(n));


  for (auto i=1; i<n; i++)
    minOps[i][i] = 0;    //number of ops are 0(zero) when there is only one matrix

  //Chain Length  varies from length 2 to length n.
  for (int chainLength=2; chainLength<n; chainLength++)
  {
    for (int i=1; i<n-chainLength+1; i++)
    {
      int j = i+chainLength-1;
      minOps[i][j] = INT_MAX;
      for (auto k=i; k<=j-1; k++)
      {
        // q = cost/scalar minOpsultiplications
        auto q = minOps[i][k] + minOps[k+1][j] + arr[i-1]*arr[k]*arr[j];
        if (q < minOps[i][j])
          minOps[i][j] = q;
      }
    }
  }

  return minOps[1][n-1];   //returning the final answer which is M[1][n]

}

#endif //MATRIXCHAIN_MATRIXCHAINTEMPLATE_H
