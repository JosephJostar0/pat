#include<iostream>
using namespace std;
int main(){
	int ar[104];
	int N,M;
	cin>>N>>M;
	int i;
	int f=(N-M%N)%N;
	for(i=0;i<N;i++)
		cin>>ar[i];
	for(i=f;i!=(f+N-1)%N;i=(i+1)%N)
		cout<<ar[i]<<' ';
	cout<<ar[(f+N-1)%N]<<endl;
	return 0;
}
