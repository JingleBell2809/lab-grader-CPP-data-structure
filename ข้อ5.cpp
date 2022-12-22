#include<iostream>
using namespace std;
class Node{
 public:
  int data;
  Node *next=NULL;
 Node(int data){
  this->data=data;
 }
};
class Link{
 public:
 Node *head=NULL;
 Node *tail=NULL;
 int size;
 
 void addf(int value){
  Node *n=new Node(value);
  if(head==NULL&tail==NULL){
   head=n;
   tail=n;
  }
  else{
   tail->next=n;
   tail=n;
  }
 }
 
 void addb(int value){
  Node *n=new Node(value);
  if(head==NULL&tail==NULL){
   head=n;
   tail=n;
  }
  else{
   n->next=head;
   head=n;
  }
 }
 
 void ins(int value,int ch){ 
   Node *n = new Node(value);
   if(head==NULL&&tail==NULL){
    head = n;
    tail = n; 
   }
   else if(ser(value) == true){ // to prevent insert the same data in link list
   // cout << "Already" << endl;
    return;
   }
   else{
    if(ser(ch) == false){
   //  cout << "Before" << endl;
     n->next = head;
     head = n;
    }
    else{
     for(Node *c=head;c!=NULL;c=c->next){
      if(c->data == ch){
       if(c == tail){
        tail = n;
       }
       n->next = c->next;
       c->next = n;
      }
     }
     
    }
   }
   print();
  }
  
  void sort(){
   for(Node *i=head;i!=NULL;i=i->next){
    for(Node *j=i;j!=NULL;j=j->next){
     if(j->data < i->data){
      int temp=j->data;
      j->data=i->data;
      i->data=temp;
     }
    }
   }
  }

  void remove(int value){
   if(head==NULL){
    return;
   }
   else if(head->data==value){
    Node *t=head;
    head=head->next;
    t->next=NULL;
   }
   else{
    for(Node *c=head;c!=NULL;c=c->next){
     if(c->next != NULL && c->next->data == value){
      c->next = c->next->next;
      break;
     }
     else if(c->next==tail){
      tail=c;
     }
     
    }
   }
   print();
  }
  
  bool ser(int value){
   for(Node *c=head;c!=NULL;c=c->next){
    if(c->data==value){
     return true;
    }
   }
   return false;
  }
  
  void print(){
   if(head==NULL&&tail==NULL){
    return;
   }
   else{
    for(Node *c=head;c!=NULL;c=c->next){
    cout<<c->data<<" ";  
    }
    cout<<endl;
   }
  }
 };
main(){
 Link l;
 string x;
 int a,b;
 cout<<"Welcome to LinkList";
 while(1){
  cout<<endl<<"a=Add font ,b=Add back ,i=Insert add ,d=Remove ,e=Sort ,p=Print ,o=exit"<<endl;
  cout<<"Enter: ";
  cin>>x;
  if(x=="b"){
   cin>>a;
   l.addf(a);
  }
  else if(x=="a"){
   cin>>a;
   l.addb(a);
  }
  else if(x=="i"){
   cin>>a>>b;
   l.ins(a,b);
  }
  else if(x=="d"){
   cin>>a;
   l.remove(a);
  }
  else if(x=="e"){
   l.sort();
  }
  else if(x=="p"){
   l.print();
  }
  else if(x=="o"){
   break;
  }
 }
}
