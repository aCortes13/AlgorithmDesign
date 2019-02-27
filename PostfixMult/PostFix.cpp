/*
  Evaluation Of postfix Expression in C++
  Input Postfix expression must be in a desired format.
  Operands must be integers and there should be space in between two operands.
  Only '+'  ,  '-'  , '*' and '/'  operators are expected.
*/
#include<iostream>
#include<stack>
#include<string>

class PostFix{

 private:

  // Function to verify whether a character is numeric digit.
  bool IsNumericDigit(char C)
  {
    if(C >= '0' && C <= '9') return true;
    return false;
  }



 public:

  int evaluatePostFix(std::string expr){

    std::stack<int> S;

   ///your code here////
     
    return S.top();
    }
};