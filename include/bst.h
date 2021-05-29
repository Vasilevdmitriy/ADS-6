// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include<string>
#include <cassert>

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
    int depthTree(Node*);
    int searchNode (Node*,T);
    void delTree(Node*);
  public:
    BST();
    ~BST();
  void add(T);
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
  } else if(root -> temp == temp){
      root-> count ++;
      return root;
  } else if(root -> temp > temp){
      root -> left =addNode(root->left, temp);
  } else {
       root -> right =addNode(root->right, temp);
  }
  return root;
}

template<typename T>
void BST<T>::delTree(Node * root)
{if(root == nullptr)return;
else {
    delTree(root -> left);
    delTree(root -> right);
    delete root;
}
}

template < typename T >
void BST <T >:: add ( T temp ) {
root = addNode ( root , temp ) ;
}

template < typename T >
int BST<T>::depthTree(Node *root){
    if(root == nullptr) return 0;
    else {
        int lh = depthTree(root->left);
        int rh = depthTree(root->right);
        return ((lh>rh)?lh:rh)+1;
    }
}

template < typename T >
int BST <T >:: depth () {
return depthTree( root);
}





#endif  // INCLUDE_BST_H_
