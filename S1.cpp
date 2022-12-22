#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    int a[1000];
    int size =0;

    void Push(int data)
    {
        a[size] = data;
        size++;
    }

    int Pop()
    {
        if (size == 0)
        {
            return -1;
        }
        else
        {
            int s = a[size - 1];
            size = size - 1;
            return s;
        }
    }

    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    int Dequeue()
    {
        if (size > 0)
        {
            int s = a[0];
            for (int i = 1; i < size; i++)
            {
                a[i - 1] = a[i];
            }

            size = size - 1;
            return s;
        }
        return -1;
    }
    void Enqueue(int data)
    {
        a[size] = data;
        size++;
    }
    bool isEmpty() 
    {
        return size==0;             
    }

};

main()
{
    int x=0;
    Stack s;
    string str;
    cin>>str;
    
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='(')
        {
            s.Push(str[i]);
            x++; 
        }
        if (str[i]==')')
        {
            s.Pop();  
            x--; 
        }
        
    }
    if (s.isEmpty()&&x==0)
    {
        cout << "PASS";
    }
    else
    {
        cout << "ERROR";
    }
    
}
