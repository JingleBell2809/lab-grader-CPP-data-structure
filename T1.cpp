#include <iostream>

using namespace std;

class Node{
	public:
		string key;
		Node *left;
		Node *right;
		
		Node(){
			this->left = NULL;
			this->right = NULL;
		}
		Node(string key){
			this->key = key;
			this->left = NULL;
			this->right = NULL;
		}
};

class BST{
	public:
		Node *root;
	
		BST(string key){
			root = new Node(key);
		}
		
		void showInOrder(Node *root){
			if(root == NULL){
				return;
			}
			else{
				showInOrder(root->left);
				cout << root->key << ",";
				showInOrder(root->right);
			}
		}
		void showPreOrder(Node *root){
			if(root == NULL){
				return;
			}
			else{
				cout << root->key << ",";
				showPreOrder(root->left);			
				showPreOrder(root->right);
			}
		}
		void showPostOrder(Node *root){
			if(root == NULL){
				return;
			}
			else{
				showPostOrder(root->left);			
				showPostOrder(root->right);
				cout << root->key << ",";
			}
		}
		void levelbfs(Node *root){
			int h=3;
			for(int i=0; i<=3; i++){
				bfs(root,i);
				cout<<"|";
			}
		}
		void bfs(Node *root,int level){
			if(root == NULL){
				return ;
			}else{
				if(level == 0){
					cout<<root->key<<",";
				}else{
					bfs(root->left,level-1);
					bfs(root->right,level-1);
				}
			}
		}
};

int main(){
	Node *bst1 = new Node("2");
	Node *bst2 = new Node("+");
	Node *bst3 = new Node("4");
	Node *bst4 = new Node("+");
	Node *bst5 = new Node("15");
	Node *bst6 = new Node("*");
	Node *bst7 = new Node("30");
	Node *bst8 = new Node("-");
	Node *bst9 = new Node("252");
	BST *bst;
	bst4->left=bst2;
	bst4->right=bst6;
	bst2->left=bst1;
	bst2->right=bst3;
	bst6->left=bst5;
	bst6->right=bst8;
	bst8->left=bst7;
	bst8->right=bst9;
	
	bst->levelbfs(bst4);
	cout<<endl;
	bst->showInOrder(bst4);
	cout<<endl;
	bst->showPreOrder(bst4);
	cout<<endl;
	bst->showPostOrder(bst4);
}
