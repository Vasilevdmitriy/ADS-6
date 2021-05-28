// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include<string>

template<typename T>
class BST{
  public:
struct Node{
  T temp;
  int count;
  Node* left;
  Node* right;
};
  private:
    Node* root;
    Node* addNode (Node*,T);
    void printTree(Node*);
    int depthTree(Node*);
    int searchNode (Node*,T);
  public:
    BST();
    ~BST();
  void add(T);
  void print();
   int depth();
  int search(T);
};
template<typename T>
BST<T>::BST():root(nullptr){}

template<typename T>
BST<T>::~BST(){
  if(root)
    delTree(root);
}

template<typename T> 
typename BST<T>::Node* BST<T>::addNode(Node *root,  T temp) { 
  if(root==nullptr) { 
    root = new Node; 
    root -> temp=temp; 
    root -> count=1; 
    root -> left =nullptr;
    root -> right =nullptr;
  } else if(root -> temp =temp){
      root-> count ++;
      return root;
  } else if(root -> temp > temp){
      root -> left =addNode(root->left, temp);
  } else {
       root -> right =addNode(root->right, temp);
  }
  return root;
}
 





#endif  // INCLUDE_BST_H_
