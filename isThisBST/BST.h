#ifndef BINARYSORTTREE_BST_H
#define BINARYSORTTREE_BST_H

#include<iostream>
#include<string>
#include<limits.h>


// create Tree
struct Node {
  Node(int value): key(value), left(nullptr), right(nullptr) {}
  int key;
  struct Node *left, *right;
};

struct Trunk
{
  Trunk * prev;
  std::string str;

  Trunk(Trunk * prev, std::string str)
  {
    this->prev = prev;
    this->str = str;
  }
};




class BST {

 private:

  Node *root;
  Trunk *prev;

  bool isLeft;

  void insert(Node *treeNode, int key);
  bool isBalanced(Node *treeNode);
  int  getHeight(Node *treeNode);
  void deleteBST(Node *treeNode);
  void inOrder(Node * treeNode);
  void preOrder(Node * treeNode);
  void postOrder(Node * treeNode);
  void printEvenNode(Node * treenode);
  bool isComplete(Node* root, int i, int n);
  void showTrunks(Trunk *p);
  void printTree(Node *root, Trunk *prev, bool isLeft);
  bool isBST(Node * treeNode, int min, int max);




 public:
  BST();  // constructor
  ~BST(); // destructor

  void insert(int data){ insert(root, data);}

  int getHeight(){return getHeight(root);}
  Node * getMaxNode();
  Node * getMinNode();

  void deleteBST() {deleteBST(root);}

  bool isBalanced(){return isBalanced(root);        }

  void inOrder() {inOrder(root);}
  void preOrder(){preOrder(root);}
  void postOrder(){postOrder(root);}
  void printEvenNode() {printEvenNode(root);}
  bool isComplete(int n) {
    std::cout << std::endl;
    return isComplete(root, 0, n);
  }
  void printTree() {printTree(root, prev, isLeft);}
  bool isBST(){
    return(isBST(root, INT_MIN, INT_MAX));
  }
  void setRoot(Node * aroot){

    root = aroot;
  }
};

////////////////////////////////////////////////////////////////////////////////////////
BST::BST()
{
  root = NULL;
}



////////////////////////////////////////////////////////////////////////////////////////
void BST::insert(Node *treeNode, int key)
{
  if (!treeNode)
  {
    treeNode = new Node(key);
    root = treeNode;
  }
  else
  {
    if (key < treeNode->key)
    {
      if (!treeNode->left)
      {
        auto *treeTemp = new Node(key);
        treeNode->left = treeTemp;
      }
      else
        insert(treeNode->left, key);
    }
    else
    {
      if (!treeNode->right)
      {
        auto *treeTemp = new Node(key);
        treeNode->right = treeTemp;
      }
      else
        insert(treeNode->right, key);
    }
  }
}

/////////////////////////////////////////////////////////////////////////////////////////
int BST::getHeight(Node *treeNode)
{
  if (!treeNode)
    return 0;
  return 1 + std::max(getHeight(treeNode->left) , getHeight(treeNode->right));
}

/////////////////////////////////////////////////////////////////////////////////////////
bool BST::isBalanced(Node *treeNode)
{
  if (!treeNode)
    return false;
  int leftHeight = getHeight(treeNode->left);
  int rightHeight = getHeight(treeNode->right);

  if (abs(leftHeight - rightHeight) > 1)
    return false;
  return true;
}

/////////////////////////////////////////////////////////////////////////////////////////
Node * BST::getMaxNode() {
  if (!root)
  {
    std::cout <<  " the BST is empty!" << std::endl;
    return nullptr;
  }
  Node * treeNode = root;
  while(treeNode->right)
    treeNode = treeNode ->right;
  return treeNode;
}

/////////////////////////////////////////////////////////////////////////////////////////
Node * BST::getMinNode() {
  if (!root)
  {
    std::cout <<  " the BST is empty!" << std::endl;
  }
  Node * treeNode = root;
  while(treeNode->left)
    treeNode = treeNode ->left;
  return treeNode;
}

/////////////////////////////////////////////////////////////////////////////////////////
void BST::deleteBST(Node *treeNode)
{
  if (!treeNode)
    return;

  Node * curTreeNode = treeNode;
  Node * leftTreeNode = treeNode->left;
  Node * rightTreeNode = treeNode->right;
  delete(curTreeNode);
  deleteBST(leftTreeNode);
  deleteBST(rightTreeNode);
}

/////////////////////////////////////////////////////////////////////////////////////////
BST::~BST()
{
  deleteBST();
}

/////////////////////////////////////////////////////////////////////////////////////////
void BST::inOrder(Node * treeNode)
{
  if (!treeNode)
    return;
  inOrder(treeNode->left);
  std::cout << treeNode->key << " " ;
  inOrder(treeNode->right);
}

/////////////////////////////////////////////////////////////////////////////////////////
void BST::preOrder(Node * treeNode)
{
  if (!treeNode)
    return;
  std::cout << treeNode->key << " ";
  preOrder(treeNode->left);
  preOrder(treeNode->right);
}

/////////////////////////////////////////////////////////////////////////////////////////
void BST::postOrder(Node * treeNode)
{
  if (!treeNode)
    return;
  postOrder(treeNode->left);
  postOrder(treeNode->right);
  std::cout << treeNode->key << " ";
}

/////////////////////////////////////////////////////////////////////////////////////////
// Function to print all even nodes
void BST::printEvenNode(Node * treeNode) {
  if (treeNode != nullptr) {
    printEvenNode(treeNode->left);
    // if node is even then print it
    if (treeNode->key % 2 == 0)
      std::cout<< treeNode->key << " ";
    printEvenNode(treeNode->right);
  }

}


//////////////////////////////////////////////////////////////////////////////////////////

bool BST::isComplete(Node* root, int i, int n) {

  // return if tree is empty
  if(root == nullptr)
    return true;

  if ((root->left && 2*i + 1 >= n) || !isComplete(root->left, 2*i + 1, n))
    return false;

  if ((root->right && 2*i + 2 >= n) || !isComplete(root->right,2* i + 2, n))
    return false;

  return true;
}

///////////////////////////////////////////////////////////////////////////////////////////

// Helper function to print branches of the binary tree
void BST::showTrunks(Trunk *p)
{
  if (p == nullptr)
    return;

  showTrunks(p->prev);

  std::cout << p->str;
}

///////////////////////////////////////////////////////////////////////////////////////////

// Recursive function to print binary tree
// It uses inorder traversal
void BST::printTree(Node *root, Trunk *prev, bool isLeft)
{
  if (root == nullptr)
    return;

  std::string prev_str = "	";
  Trunk *trunk = new Trunk(prev, prev_str);

  printTree(root->left, trunk, true);

  if (!prev)
    trunk->str = "---";
  else if (isLeft)
  {
    trunk->str = ".---";
    prev_str = "	|";
  }
  else
  {
    trunk->str = "`---";
    prev->str = prev_str;
  }

  showTrunks(trunk);
  std::cout << root->key << std::endl;

  if (prev)
    prev->str = prev_str;
  trunk->str = "	|";

  printTree(root->right, trunk, false);
}

//////////////////////////////////////////////////////////////////////////////////////////////

bool BST::isBST(Node* node, int minKey, int maxKey) {
  if (node == nullptr) return true;

  if (minKey > node->key || maxKey < node->key) return false;

  return(isBST(node->left, minKey, node->key) && isBST(node->right, node->key, maxKey));
}

#endif //BINARYSORTTREE_BST_H