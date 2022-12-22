#include<iostream>
#include<string>
#include<stdlib.h> 
#include<stdio.h> 
#include<math.h>
#include<vector> 
#include<algorithm> 

using namespace std;
int sum=0;

void ls(int value,int a[],int l,int r){
	for(int i = l;i<r;i++){
		sum++;
		if(a[i] == value){
			cout<<i<<" "<<value<<endl;
		}
		else if(a[i]>value){
			int b;
			int c;
			if(abs(a[i]-value) < abs(a[i-1] - value)){
				b=a[i];
				c=i;
			}
			else{
				b=a[i-1];
				c=i-1;
			}
			cout<<c+1<<" "<<b<<endl;
			break;
		}
	}

			
}
int main() 
{
	int n;
	cin>>n;
	int value;
	int a[n];
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	
	cin>>value;
	
	ls(value,a,0,n-1);


  	return 0;
}


