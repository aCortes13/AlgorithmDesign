//code modified from https://www.geeksforgeeks.org/delete-middle-element-stack/ code
#include<iostream>
#include <stack>
#include "deleteMid.cpp"



int main()
{
  std::stack<int> st;

  //push elements into the stack
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.push(5);
  st.push(6);
  st.push(7);

  DeleteMid myDeleteMid;

  myDeleteMid.deleteMid(st, (int)st.size());  // note the difference in number of variables

  // Printing stack after deletion
  // of middle.
  while (!st.empty())
  {
    auto p=st.top();
    st.pop();
    std::cout << p << " ";
  }
  return 0;
} 
  return 0;
} 