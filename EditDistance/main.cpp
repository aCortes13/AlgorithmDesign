// operations to convert str1 to str2
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "EditDistanceDynamic.h"

// Driver program
int main(){
  // your code goes here
  std::string str1 = "sunday";
  std::string str2 = "saturday";

  std::cout << editDist( str1 , str2);

  return 0;
}