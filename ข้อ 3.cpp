#include <bits/stdc++.h>

using namespace std;

class Node{
	public:
		int value;
		Node *next;
		
		Node(int value)
		{
			this->value = value;
		}
};
class Linked_List{
	public:
		Node *head;
		int size = 0;
        int min = 10000;
		Linked_List(int value)
		{
			head = new Node(value);
			head->next = NULL;
			size = 1;
		}
        void InsertNode(int value)
		{
			int my_index = 1;
			for( Node *h = head ; h != NULL ; h = h->next)
			{        
				if(size == 0)  
				{    
					Node *h = new Node(value);
					h->next = head;   
					head = h;    
					break;   
				}
				if(my_index == size )
				{        
					h->next = new Node(value);   
					h->next->next = NULL;   
					break;   
				}
				my_index++; 
				
			}  
			size++;
		}
		void minx(){
			int min =100000 ;
			for(Node *h = head ; h != NULL ; h = h->next){
				if(h->value < min){
					min = h->value;
				}
			}
			for(Node *h = head ; h != NULL ; h = h->next){
					if(h->value == min){
						InsertNode(min);
						h->next = h->next->next;
						break;
					}
				}
			for(Node *h = head ; h != NULL ; h = h->next){
					if(h->next->value == min){
						h->next = h->next->next;
						break;
					}
				}
		}
		void print(){
			for(Node *h = head ; h != NULL ; h = h->next){
				if(h->next==NULL){
					cout << h->value << " ";
				}
			}
		}
};
int main(){
	
    Linked_List *l = new Linked_List(20);
    l->InsertNode(305);
	l->InsertNode(98);
	l->InsertNode(11);
	l->InsertNode(32);
	l->InsertNode(458);
	l->InsertNode(55);
	l->InsertNode(69);
	l->InsertNode(78);
	l->minx();
	l->print();
}
