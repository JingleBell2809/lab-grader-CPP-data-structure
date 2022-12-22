#include <bits/stdc++.h>

using namespace std;

class Node{
	public:
		int key;
		Node *left;
		Node *right;
		
		Node(){
			this->left = NULL;
			this->right = NULL;
		}
		Node(int key){
			this->key = key;
			this->left = NULL;
			this->right = NULL;
		}
};

class BST{
	public:
		Node *root;
		BST(int key){
			root = new Node(key);
		}
		
		int Max(Node* root){
			if (root->right == NULL){
				return root->key;
			}
			return Max(root->right);
		}
		
		int searchKey(Node *root, int key){
			if(root == NULL){
				return -1;
			}
			else{
				if(key == root->key){
					return 1;
				}
				else if(key > root->key){
					return searchKey(root->right, key);
				}
				else{
					return searchKey(root->left, key);
				}	
			}
		}
		
		int searchKeyOther(Node *root,int key,int x){
			if(key > x) {
				return x;
			}
			else {
				findlow(key);
				int b = key+2;
				return b;
			}
		}
		
		void findlow(int key){
			int a = key-2;
			cout << a << " ";
		}
		Node* insertNode(Node *root, int key){
			if(root == NULL){
				root = new Node(key);
			}
			else{
				if(key > root->key){
					root->right = insertNode(root->right, key);
				}
				else{
					root->left = insertNode(root->left, key);
				}
			}
			return root;
		}
		void showInOrder(Node *root){
			if(root == NULL){
				return;
			}
			else{
				showInOrder(root->left);
				cout << root->key << " ";
				showInOrder(root->right);
			}
		}
		
};

int main(){
	BST *bst2 = new BST(1);
	
	bst2->insertNode(bst2->root,3);
	bst2->insertNode(bst2->root,5);
	bst2->insertNode(bst2->root,7);
	bst2->insertNode(bst2->root,9);
	bst2->insertNode(bst2->root,11);
	bst2->insertNode(bst2->root,15);
	bst2->insertNode(bst2->root,17);
	bst2->insertNode(bst2->root,19);
	int x = bst2->Max(bst2->root);
	bst2->showInOrder(bst2->root);
	cout << endl;
	
	cout << bst2->searchKeyOther(bst2->root,5,x) << endl;
	int b = bst2->searchKeyOther(bst2->root,21,x);
	cout << b <<endl;
	
	return 0;
}
