#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
	Node *next;
	int	value;
	string name;	
	
	Node(int value,string name)
	{
		this->value = value;
		this->name = name;	
	}
};

class Link_List																
{
	public:
		Node *head;
		int size = 0;
		Link_List(int value, string name)	
		{
			head = new Node(value,name);
			head->next = NULL;
			size = 1;																
		}
		void AddNode(int value, string name)												 
		{
			Node *h = new Node(value,name);
			h->next = head;
			head = h;
			size++;
		}
		void PrintList()
		{
			for( Node *h = head ; h != NULL ; h = h->next )
			{
				cout<<h->value<<","<<h->name<<" ";
			}
		}
		int Search_Index( int value )
		{
			int i = 0;
			for( Node *h = head ; h != NULL ; h = h->next )
			{
				if( value == h->value)
				{
					return i;
				}
				i++;
			}
			return -1;
		}
		void InsertNode_after(int index, int value, string name)   
		{
			if(index <= size && index > -1)     
			{
				bool complete_insert = 0;
				int my_index = 0;
				for( Node *h = head ; h != NULL ; h = h->next )
				{										
					if(my_index == size && index == size)	
					{																
						h->next = new Node(value,name);
						h->next->next = NULL;
						complete_insert = 1;
						break;
					}
					else if( my_index == index )							 
					{																						
						Node *n = new Node(value,name);	
						n->next = h->next;					
						h->next = n;	
						complete_insert = 1;
						break;
					}
					my_index++;
				}
				if(complete_insert == 1){	size++;		}		
			}											
		}
		void RemoveNode(int index)
		{
			bool complete_delete = 0;
			if(index < size && index > -1)
			{	
				int my_index = 1;												
				for(Node *h = head ; h != NULL ; h = h->next)
				{
					if(index == 0)	
					{
						head = head->next;	
						complete_delete = 1;								
						break;
					}
					else if(my_index == index )						
					{
						h->next = h->next->next;		
						complete_delete = 1;				
						break;
					}
					my_index++;
				}
				if(complete_delete == 1){	size--;		}	
			}
		}	
};

int main() 
{
	Link_List *l;
	int enable = 0;
	char key;
	int value, y;
	string name;
	
	while(1)
	{
		cin>>key;
		if(key == '1')
		{
			cin>>value;	 	
			cin>>name;
			cin>>y;  		
			if(enable == 0)
			{
				l = new Link_List( value,name );
				enable = 1;
			}
			if( l-> Search_Index(value) == -1) 
			{
				int t_index = l-> Search_Index(y);
				if(t_index == -1)
				{
					l->AddNode(value, name); 
				}
				else
				{	
					l->InsertNode_after(t_index, value, name); 
				}
			}
			l->PrintList(); cout<<endl;
		}
		else if(key == '0')
		{
			cin>>value;	 	
			int t_index = l-> Search_Index(value);
			if( t_index != -1 && l->size > 1)
			{ 
				l->RemoveNode(t_index);  
			}
			l->PrintList(); cout<<endl;
		}
		else
		{
			break;
		}	
	}
	return 0;
}