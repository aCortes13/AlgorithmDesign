#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Utility function to find minimum of three numbers
int min3(int x, int y, int z){
  return std::min(std::min(x, y), z);
}

int editDist(std::string str1 , std::string str2){
   
    std::vector<std::vector<int>> table (str1.length()+1,std::vector<int> (str2.length()+1));

----------------------your code ----------------------------

   return table[m][n];
}