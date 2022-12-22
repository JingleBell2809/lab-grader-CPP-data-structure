#include<iostream>
#include<string>
#include<stdlib.h> 
#include<stdio.h> 
#include<math.h>
#include<vector> 
#include<algorithm> 

using namespace std;
int sum=0;

bool bs(int value,int a[],int l,int r){
	sum++;
	int mid = (l+r)/2;
	if(l>r){
		return false;
	}
	if(a[mid] == value){
		return true;
	}
	else if(a[mid] > value){
		bs(value,a,l,mid-1);
	}
	else if(a[mid] < value){
		bs(value,a,mid+1,r);
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
	if(bs(value,a,0,n-1)){
		cout<<sum<<endl;
		cout<<value<<endl;
	}else{
		cout<<-1<<endl;
		cout<<value<<endl;
	}


  	return 0;
}


