#include<iostream>
#include "BST.h"

int main()
{

  BST myTree;

  Node * nn1 = new Node(50);
  Node * nn2 = new Node(30);
  Node * nn3 = new Node(60);

  nn1->left = nn3;
  nn1->right =nn2;

  myTree.setRoot(nn1);



  //myTree.printEvenNode();
  (myTree.isBST())?std::cout <<"BST":std::cout <<"not BST";

  //std::cout<<std::endl;

   //myTree.printTree();

  return 0;
}