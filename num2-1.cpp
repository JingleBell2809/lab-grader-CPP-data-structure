#include<iostream>
#include<string>
#include<stdlib.h> 
#include<stdio.h> 
#include<math.h>
#include<vector> 
#include<algorithm> 

using namespace std;
int sum=0;

bool ls(int value,int a[],int l,int r){
	for(int i = l;i<r;i++){
		sum++;
		if(a[i] == value){
			return true;
		}
	}
	return false;
			
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
	
	if(ls(value,a,0,n-1)){
		cout<<sum<<endl;
		cout<<value<<endl;
	}else{
		cout<<-1<<endl;
		cout<<value<<endl;
	}


  	return 0;
}


