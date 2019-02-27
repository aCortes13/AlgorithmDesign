#include<iostream>
#include<stack>
#include<string>
#include "PostFix.cpp"

int main(){

  PostFix myPostFix;

  std::string expression { "50 1 2 + 4 * + 3 -"};

  int answer = myPostFix.evaluatePostFix(expression);

  std::cout <<answer;
}