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

  int evaluatePostFix(std::string expr) {

    std::stack<int> S;
    for (int i = 0; i < expr.length();i++) {
      if (expr[i] == ' ') { continue; }

      if(isdigit(expr[i])) {
        int val = 0;

        while (i < expr.length() && isdigit(expr[i])) {
          val = (val*10) + (expr[i]-'0');
          i++;
        }

        S.push(val);
      }
      else {
        char c = expr[i];
        int left = S.top();
        S.pop();
        int right = S.top();
        S.pop();

        switch (c) {
          case '*':
            S.push(left * right);
            break;

          case '/':
            S.push(left / right);
            break;

          case '+':
            S.push(left + right);
            break;

          case '-':
            S.push(right-left);
            break;

          default:
            break;
        }
      }
    }

    return S.top();
  }
};