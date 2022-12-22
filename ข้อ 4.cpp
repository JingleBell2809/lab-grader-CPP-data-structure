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
        Node(){
            this->value = 0 ;
        }
};

class Linked_List{
	public:
		Node *head;
		int size = 0;
		Linked_List()
		{
			head = new Node();
			head->next = NULL;
			size = 0;
		}
        void addNode(int value)
		{
			int check = 0 ;
			for( Node *h = head ; h != NULL ; h = h->next)
			{
				if(value < h->value){
					break ;
				}
				check++;
			}
			int my_index = 1 ;
			for( Node *h = head ; h != NULL ; h = h->next)
			{        
				if(size == 0)  
				{    
					h->value = value ;     
					break;	   
				}else if (check == 0)
				{
					Node *h = new Node(value);
					h->next = head;
					head = h;
					break ;
				}
				
				else if(my_index == check ){
                    Node *n = new Node(value);   
					n->next = h->next;   
					h->next = n;      
					break ;
                }
				else if(h->next ==NULL )
				{        
					h->next = new Node(value);   
					h->next->next = NULL;   
					cout << "4" <<endl;    
					break;   
				}
				
				my_index++; 
				
			}
			size++;
		}
        void Dequeue(){
			int num = 0 ;
			for(Node *h = head ; h != NULL ; h = h->next){
				if(num==0){
					cout << "Dequeue ->" << h->value << endl;
					num++;
					head = h->next;
				}
				cout << h->value << " ";
			}
			cout<<endl;
		}
		void print(){
			cout << "queue -> " ;
			for(Node *h = head ; h != NULL ; h = h->next){
				cout << h->value << " ";
			}
			cout<<endl;
		}
};
int main(){
    int input;
    Linked_List *l = new Linked_List();
    for(int i = 0 ; i< 10 ; i++){
        cin >> input ;  
        l->addNode(input);
    }
	l->print();
	int choice ;
	while (true)
	{
		cout<< "[1]input 1 more  \n[2]Dequeue  \n[3]Exit"<< endl ;
		cin>>choice;
		if(choice == 1){
			cin>> input;
			l->addNode(input);
			l->print();
		}
		else if(choice == 2 ){
			l->Dequeue();
		}else{
			break ;
		}	
	}
}
