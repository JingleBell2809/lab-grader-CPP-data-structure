#include<bits/stdc++.h>
using namespace std;
int arr[100]={0};

int size=0;
int i;
int key;
int n;
int a;

int addfront(int num)
{
 int Q=0;
 for(i=0;i<size;i++)
 {
  if(num==arr[i])
  {
   Q=1;
  }
 }
 if(Q==0)
 {
  size++;
  for(i=size-1;i>=0;i--)
  {
   arr[i+1]=arr[i];
  }
  arr[0]=num;
 }
}

int addback(int num)
{//3 4 5 :3
 int Q=0;
 for(i=0;i<size;i++)
 {
  if(num==arr[i])
  {
   Q=1;
  }
 }
 if(Q==0)
 {
  size++;
  arr[size-1]=num;
 }
}

int insert(int num,int address)
{
 int Q=0;
 for(i=0;i<size;i++)
 {
  if(num==arr[i])
  {
   Q=1;
  }
 }
 if(Q==0)
 {
  size++;
  for(i=size-1;i>=address;i--)
  {
   arr[i+1]=arr[i];
  }
  arr[address]=num;
 }
}
int delet(int address)
{//5 .. 3
 if(size>0)
 {
  for(i=address;i<size;i++)
  {
   arr[i]=arr[i+1];
  }
  size--;
 }
}
int print()
{
 for(i=0;i<size;i++)
 {
  cout<<arr[i]<<" ";
 }
 cout<<"|size is "<<size<<endl;
 
}
int main()
{
 while(true)
 {
  cout<<"1=Add Front, 2=Add Back, 3=Insert, 4=Delete, 5=Print, 6=Exit"<<endl;
  cout<<"Enter code: ";
  cin>>key;
  if(key==1)
  {
   cout<<"Enter number: ";
   cin>>n;
   addfront(n);
  }
  else if (key==2)
  {
   cout<<"Enter number: ";
   cin>>n;
   addback(n);
  }
  else if (key==3)
  {
   cout<<"Enter number: ";
   cin>>n;
   cout<<"Enter address: ";
   cin>>a;
   insert(n,a);
   
  }
  else if (key==4)
  {
   cout<<"Enter address: ";
   cin>>a;
   delet(a);
  }
  else if (key==5)
  {
   print();
  }
  else if (key==6)
  {
   break;
  }
 }

}
