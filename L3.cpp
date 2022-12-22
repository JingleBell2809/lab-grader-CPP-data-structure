#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
	Node *next;
	int	value;	
	
	Node(int value)
	{
		this->value = value;	
	}
};

class Link_List																
{
	public:
		
	Node *head;
	int size = 0;
	
	Link_List(int value)	
	{
		head = new Node(value);
		head->next = NULL;
		size = 1;																
	}
	
	void AddNode(int value)												 
	{
		for( Node *h = head ; h != NULL ; h = h->next )
		{
			if( h->next == NULL )
			{
				h->next = new Node(value);							
				h->next->next = NULL;									
				break;															
			}
		}
		size++;
	}

	void PrintList()
	{
		for( Node *h = head ; h != NULL ; h = h->next )
		{
			cout<<h->value<<" ";
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

	void InsertNode_before(int index, int value)   
	{
		if(index <= size && index > -1)     
		{
		bool complete_insert = 0;
		int my_index = 1;
		for( Node *h = head ; h != NULL ; h = h->next )
		{										
			if(index == 0)												
			{
				Node *h = new Node(value);
				h->next = head;
				head = h;
				complete_insert = 1;
				break;
			}
         	else if(my_index == size && index == size)	
			{																
				h->next = new Node(value);
				h->next->next = NULL;
				complete_insert = 1;
				break;
			}
			else if( my_index == index )							 
			{																						
				Node *n = new Node(value);	
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
	int x,y;
	while(1)
	{
		cin>>key;
		if(key == 'a')
		{			
			cin>>x;	 
			cin>>y;  
			if(enable == 0)
			{
				l = new Link_List( x );
				enable = 1;
			}
			if( l-> Search_Index(x) == -1) 
			{
				int t_index = l-> Search_Index(y);
				if(t_index == -1)
				{
					l->AddNode(x); 
				}
				else
				{	
					l->InsertNode_before(t_index, x); 
				}
			}
		}
		else if(key == 'r')
		{
			cin>>x;
			int t_index = l-> Search_Index(x);
			if( t_index != -1 && l->size > 1)
			{ 
				l->RemoveNode(t_index);  
			}
		}
		else if(key == 'p')
		{
			l->PrintList(); cout<<endl;
		}
		else if(key == 'e')
		{
			break;
		}	
	}
	return 0;
}
