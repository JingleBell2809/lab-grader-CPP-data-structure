#include<bits/stdc++.h>
using namespace std;

class Queue
{
	public:
		int a[1000]; 
   		int size = 0;
    void Enqueue(int data)
    {
       	a[size] = data; 
       	size++;
    }
    void first_end()
    {
    	if(size > 0)
    	{
       		cout<<a[0]<<" "<<a[size-1]<<endl; 
       	}
    }
  	void Print()
    {
		for (int i = 0; i < size; i++)			
		{ 
 			cout << a[i] << " ";
		}
		cout<<endl;
    }
    int Dequeue() 
    {
        if( size > 0 )
        {
          int s = a[0];
          for(int i=1 ; i < size ; i++)
          {
             a[i-1] = a[i];
          }      
          size = size -1;
          return s;
        }
        return -1;
    }
};

int main() 
{
	int x;
	char key;
	Queue s;

	while(1)
	{
		cin>>key;
		if(key == 'e')
		{
			cin>>x;
			s.Enqueue(x);	 
		}
		else if(key == 'd')
		{
			cout<<s.Dequeue()<<endl;
		}
		else if(key == 's')
		{
			s.first_end();
		}
		else if(key == 'p')
		{
			s.Print();
		}
		else if(key == 'n')
		{
			cout<<s.size<<endl;
		}	
		else if(key == 'x')
		{
			break;
		}	
	}
	return 0;
}
