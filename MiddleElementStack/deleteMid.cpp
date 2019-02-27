#include<iostream>
#include<cmath>
#include<cstdio>
#include<stack>

class DeleteMid{

 public:

  void deleteMid(std::stack<int> &mystack, int n, int curr=0){
    if (mystack.empty() || curr == n)
      return;

    int temp = mystack.top();
    mystack.pop();
    deleteMid(mystack, n, curr+1);

    if (curr != n/2)
      mystack.push(temp);

  }
};
/*if all elements traversed or stack is empty - return
 *
 * temp frame variable = element on top pop the element

    recursively call remove mid which puts each element into a different frame until you have popped them all

    then the last frame returns and checks that its curr value is not equal to n/2

if it isnt, the tempStackvaraible value gets pushed onto the stack

    Oviously for an even size stack you get the floor value as the middle

The key to understanding this type of recursion:

portions of code

1) check for all elements popped - return which starts the frames collapsing
2) else move top element into a temp var
3) recursively call function incrementing
  the curr counter value so each frame knows where it is in
  the stack EACH FRAME EXECUTES UP TO HERE AND WAITS FOR A RETURN TO CONTINUE EXECUTING!!!!

4) THE COLLAPSE EXECUTES STARTING HERE!! - check for middle value put everything else back on stack

 */