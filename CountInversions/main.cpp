#include <iostream>
#include <vector>
#include "CntInv.cpp"
#include <iterator>
#include <sstream>
int main() {

  std::vector<int> input {6,5,4,3,2,1};

  Solution mysolution;
  auto numInv = 0;

  std::vector<int> out;

  out = mysolution.cntInv(input,numInv);

  std::cout<< numInv <<std::endl;

  for(int x:out){std::cout<<x<<" ";}

  return 0;
}