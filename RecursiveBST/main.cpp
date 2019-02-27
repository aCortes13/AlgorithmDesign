#include<iostream>
#include "PrintEvens.cpp"

int main()
{

 BST myTree ;


  /* Let us create following BST
     5
    / \
   3     7
  / \ / \
  2 4 6 8 */
  //Node* root = NULL;

  myTree.insert(5);
  myTree.insert(3);
  myTree.insert(7);
  myTree.insert(2);
  myTree.insert(4);
  myTree.insert(6);
  myTree.insert(8);

  myTree.printEvenNode();
 (myTree.isComplete(7))?std::cout <<"complete":std::cout <<"not complete";





  return 0;
} 