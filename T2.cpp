#include <iostream>
using namespace std;

class Node{
 public:
  int data;
  Node *left;
  Node *right;
  Node(){
   this->left = NULL;
   this->right = NULL;
  }
  Node(int data){
   this->data = data;
   this->left = NULL;
   this->right = NULL;
  }
};

class BST{
 public:
  Node *root;
  BST(int data){
   root = new Node(data);
  }
  Node* Insert(Node *root, int data){
   if(root == NULL){
    root = new Node(data);
   }
   else{
    if(data > root->data){
     root->right = Insert(root->right, data);
    }
    else{
     root->left = Insert(root->left, data);
    }
   }
   return root;
  }
  
  void Inorder(Node *root){
   if(root == NULL){
    return;
   }
   else{
    Inorder(root->left);
    cout << root->data << ",";
    Inorder(root->right);
   }
  }
  void Preorder(Node *root){
   if(root == NULL){
    return;
   }
   else{
    cout << root->data << ",";
    Preorder(root->left);   
    Preorder(root->right);
   }
  }
  void Postorder(Node *root){
   if(root == NULL){
    return;
   }
   else{
    Postorder(root->left);   
    Postorder(root->right);
    cout << root->data << ",";
   }
 }
};

main()
{
 int n,num;
 cin>>n; 
 cin>>num;
 BST *bst = new BST(num);
 for(int i=0;i<n-1;i++)
 {
  cin>>num;
  bst->Insert(bst->root,num); 
 }
 char select;
 while(true)
 {
  cin>>select;
  if(select=='I')
  {
   bst->Inorder(bst->root);
   cout << endl;
  }
  else if(select=='E')
  {
   bst->Preorder(bst->root);
   cout << endl;
  }
  else if(select=='O')
  {
   bst->Postorder(bst->root);
   cout << endl;
  }
  else if(select=='X')
  {
   break;
  }
 }
}
