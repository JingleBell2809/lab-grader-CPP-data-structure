#include<bits/stdc++.h>

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
		
		Linked_List(int value)
		{
			head = new Node(value);
			head->next = NULL;
			size = 1;
		}
		void PrintList(int m, int n)
		{
			int count=0;
			Node *h = head;
			for(int a=0; a<m; a++)
			{
				h=head;
				for(int c=0; c<count; c++)
				{
						h=h->next;
					}
				for(int i=0; i<n; i++)
				{
					cout<<h->value<<" ";
					for(int j=0; j<m&&h!=NULL; j++)
					{
						h=h->next;
					}
				}
				cout<<endl;
				count++;
			}
		}
		void InsertNode(int index, int value)
		{
			int my_index = 1;
			for( Node *h = head ; h != NULL ; h = h->next)
			{        
				if(index == 0)  
				{    
					Node *h = new Node(value);
					h->next = head;   
					head = h;    
					break;   
				}
				else if(my_index == size && index == size)
				{        
					h->next = new Node(value);   
					h->next->next = NULL;   
					break;   
				}   
				else if(my_index == index) 
				{        
					Node *n = new Node(value);   
					n->next = h->next;   
					h->next = n;   
					break;   
				} 
				my_index++;  
			}  
			size++;
		}
};
int main(){
	Linked_List *l;
	int m,n,value,count=1;
	cin>>m;
	cin>>n;
	
	cin>>value;
	l=new Linked_List(value);
	for(int i=0; i<m*n-1; i++){
		cin>>value;
		l->InsertNode(count,value);
		count++;
	}
	l->PrintList(m,n);
}
