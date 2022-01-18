#include<iostream>
#include<cmath>
using namespace std;

bool isSushu(int num){
	int i;
	for(i=2;i<=sqrt(num);i++){
		if(num%i==0)
			return false;
	}
	return true;
}

int main(){
	
	int N;
	cin>>N;
	int i,k=0,flag=1;
	for(i=2;i<=N;i++){
		if(isSushu(i)){
			if(i-flag==2)
				k++;
			flag=i;
		}
	}
	cout<<k<<endl;
}
