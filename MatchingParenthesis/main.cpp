#include <iostream>
#include <stack>
#include <string>
#include "VerifyParens.cpp"

  int main(){
  {
    std::string expr = "{()}[]";

    VerifyParens myVerify;

    if (myVerify.areParanthesisBalanced(expr))
      std::cout << "Balanced";
    else
      std::cout << "Not Balanced";
    return 0;
  }
  return 0;
} 