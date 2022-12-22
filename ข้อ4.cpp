#include<bits/stdc++.h>
using namespace std;

class Node
{
	 public:
	 Node *next;
	 int value;
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
	  head->next=NULL;
	  size=1;
	 }		 
	 void PrintList(){ 
	  for(Node *h=head ; h != NULL ; h= h->next )
	  {	   
	   cout<<h->value<<" ";
	  }
	  //if(new_my_line == 1){cout<<endl;}
	 }
	
	void InsertNode(int index, int value)
	 {
	   int my_index = 1; // differrent
	   for(Node *h = head ; h != NULL ; h =h->next)
	   {
	   if(index ==0)
	    {
	     Node *h = new Node(value);
	     h->next = head;
	     head = h;
	     break;
	    }
	    else if(my_index == size && index == size)
	    {
	     h->next = new Node(value);
	     h->next->next=NULL;
	     break;
	    }
	    else if(my_index == index)
	    {
	     Node *n = new Node(value);
	     n->next = h->next;
	     h->next =n;	     
	     break;
	    }
	    my_index++;
	   }
	   size++;
	   }
    void RemoveNode(int index){
            int my_index=1;
            for(Node *h=head;h!=NULL;h=h->next){
                if(index==0){
                    head =head->next;
                    break;
                }
                else if(my_index==index){
                    h->next=h->next->next;
                    
                    break;
                }
                my_index++;
            }
                size++;
            }
};

int main()
{   
    Link_List *l = new Link_List(18);
    l->InsertNode(0,5); 	l->PrintList(); cout<<"I"<<l->size<<endl; 
    l->InsertNode(0,10);	l->PrintList(); cout<<"I"<<l->size<<endl; 
    l->InsertNode(3,17); 	l->PrintList(); cout<<"I"<<l->size<<endl;
    l->InsertNode(4,19); 	l->PrintList(); cout<<"I"<<l->size<<endl;
    l->InsertNode(2,52); 	l->PrintList(); cout<<"I"<<l->size<<endl;
    l->InsertNode(0,9); 	l->PrintList(); cout<<"I"<<l->size<<endl;
    l->InsertNode(7,13); 	l->PrintList(); cout<<"I"<<l->size<<endl;
    l->InsertNode(2,11); 	l->PrintList(); cout<<"I"<<l->size<<endl;
    l->RemoveNode(0); 		l->PrintList(); cout<<"I"<<l->size<<endl;
    l->RemoveNode(1);		l->PrintList(); cout<<"I"<<l->size<<endl;
    l->RemoveNode(6); 		l->PrintList(); cout<<"I"<<l->size<<endl;
 return 0;
}

