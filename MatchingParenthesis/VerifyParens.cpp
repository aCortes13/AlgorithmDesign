// Created by Greg LaKomski on 2/21/19.
//


#include<iostream>
#include<cmath>
#include<cstdio>
#include <stack>

class VerifyParens {

public:


  bool areParanthesisBalanced(std::string expr) {

    std::stack<char> s;
    char x;

    for (char c : expr) {
      switch(c) {
        case '(':
            s.push(')');
            break;

        case '{':
            s.push('}');
            break;

        case '[':
            s.push(']');
            break;

        default:
            if (c == ')' || c == '}' || c == ']') {
              x=s.top();
              if (x != c) {
                return false;
              } else {
                s.pop();
              }
            }
      }

    }
    return s.empty();
  }
};
