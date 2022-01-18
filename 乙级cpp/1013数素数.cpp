#include<iostream>
#include<cmath>
using namespace std;

bool isSushu(int num){
	int k;
	for(k=2;k<=sqrt(num);k++){
		if(num%k==0)
			return false;
	}
	return true;
}

int main(){
	int M,N;
	cin>>M>>N;
	int i;
	int time=0;
	int num=0;
	for(i=2;time<N;i++){
		if(isSushu(i)){
			time++;
			if(time>=M&&time<=N){
				cout<<i;
				num++;
				if(time!=N){
					if(num%10)
						cout<<' ';
					else
						cout<<endl;
				}
				
			}
		}
	}
    cout<<endl;
	return 0;
}
