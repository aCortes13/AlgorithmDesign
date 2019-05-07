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

    int m, n;
    m = str1.length();
    n = str2.length();

    // initialize base case solution
  for (int i = 0; i <=n; i++) {
    table[0][i] =i;
  }

  for (int i = 0; i <=m; i++) {
    table[i][0] =i;
  }

  //solving it bottom-up manner

  for (int i = 1; i <=m ; i++) {
    for (int j = 1; j <=n ; j++) {

      //If last characters are matching, ignore the last character
      // then the solution will be same as without the last character.
      if (str1.at(i - 1) == str2.at(j - 1))
        table[i][j] = table[i - 1][j - 1];
      else
        table[i][j] = 1 + min3(table[i][j - 1], //Insert
                               table[i - 1][j], // Remove
                               table[i - 1][j - 1]); //Replace
    }
  }











   return table[m][n];
}