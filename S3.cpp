#include<bits/stdc++.h>
using namespace std;

class Stack
{
    public:
	int a[10000]; 
    int size = 0;
    
    void Push(int data)
    {
       a[size] = data; 
       size++;
    }
    
   	int Pop()
    {
        if(size == 0){  return -1; }
        else
        {	
          int s = a[size-1];
          size = size - 1;            
          return s;           
        }
    }
    
    int Top()
    {
    	int s = a[size-1];   
    	return s;
	}

    void Print()
    {
		for (int i = 0; i < size; i++)	
		{ 
 			cout << a[i] << " ";
		}
		cout<<endl;
    }
};

int main() 
{
	int x;
	char key;
	Stack s;
	
	while(1)
	{
		cin>>key;
		if(key == 'U')
		{
			cin>>x;
			s.Push(x);	 
		}
		else if(key == 'O')
		{
			cout<<s.Pop()<<endl;
		}
		else if(key == 'T')
		{
			cout<<s.Top()<<endl;
		}
		else if(key == 'P')
		{
			s.Print();
		}
		else if(key == 'N')
		{
			cout<<s.size<<endl;
		}	
		else if(key == 'X')
		{
			break;
		}	
	}
	return 0;
}
