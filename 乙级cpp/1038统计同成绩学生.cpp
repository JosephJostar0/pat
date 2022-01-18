#include<iostream>
using namespace std;
int main(){
	int n,k;
	int rank[101]={0};
	int i,j;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>j;
		rank[j]+=1;
	}
	cin>>k;
	for(i=0;i<k;i++){
		if(i>0)
			cout<<' ';
		cin>>j;
		cout<<rank[j];
	}
	cout<<endl;
	return 0;
}
