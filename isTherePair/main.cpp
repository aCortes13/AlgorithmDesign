#include<iostream>
#include "BST.h"

int main()
{


  BST myTree;


  Node * nn1 = new Node(50);
  Node * nn2 = new Node(30);
  Node * nn3 = new Node(60);

  Node * nn4 = new Node(25);
  Node * nn5 = new Node(40);
  Node * nn6 = new Node(55);
  Node * nn7 = new Node(65);


  Node * nn8 = new Node(24);
  Node * nn9 = new Node(26);
  Node * nn10 = new Node(39);
  Node * nn11= new Node(41);
  Node * nn12= new Node(54);
  Node * nn13 = new Node(56);
  Node * nn14 = new Node(64);
  Node * nn15 = new Node(66);



  nn1->left = nn2;
  nn1->right =nn3;
  nn2->left =nn4;
  nn2->right = nn5;
  nn3->left = nn6;
  nn3->right = nn7;

  nn4->left = nn8;
  nn4->right = nn9;
  nn5->left = nn10;
  nn5->right = nn11;
  nn6->left = nn12;
  nn6->right = nn13;
  nn7->left =nn14;
  nn7->right = nn15;

  myTree.setRoot(nn1);


  bool answer = myTree.findPair(65);
  (answer)?std::cout<<"pair found":std::cout<<"no pair";

  return 0;
}