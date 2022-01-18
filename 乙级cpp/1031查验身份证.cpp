#include<iostream>
using namespace std;

bool allright(char id[]){
	int weight[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	int p,q,z=0;
	char M[11]={'1','0','X','9','8','7','6','5','4','3','2'};
	for(p=0;p<17;p++){
		q=id[p]-'0';
		if(q<0||q>9)
			return false;
		z+=q*weight[p];
	}
	z%=11;
	if(M[z]!=id[17])
		return false;
	return true;
	
}

int main(){
	int N;
	cin>>N;
	int i;
	bool flag = true;
	char id[19];
	for(i=0;i<N;i++){
		cin>>id;
		if(!allright(id)){
			if(!flag)
				cout<<endl;
			cout<<id;
			flag = false;
		}
	}
	if(flag)
		cout<<"All passed\n";
	return 0;
}
