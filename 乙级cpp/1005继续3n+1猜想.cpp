#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

void insertsort(int in[]){
	int m,n,p;
	for(m=1;m<101;m++){
		p=in[m];
		for(n=m-1;n>=0;n--){
			if(p>in[n])
				in[n+1]=in[n];
			else
				break;
		}
		in[n+1]=p;
	}
}

int main(){
	bool how=false;
	int k;
	int flag[101]={0};
	int in[101]={0};
	cin>>k;
	int i,j;
	for(i=0;i<101;i++)
		flag[i]=0;
	for(i=0;i<k;i++){
		cin>>in[i];
		j=in[i];
		while(j>1){
			if(j%2)
				j=j*3+1;
			j/=2;
			if(j<=100){
				if(flag[j]==1)
					break;
				else
					flag[j]=1;
			}
		}
	}
	insertsort(in);
	for(i=0;i<k;i++){
		if(flag[in[i]]==0){
			if(how)
				cout<<' ';
			cout<<in[i];
			how=true;
		}
	}
	cout<<endl;
	return 0;
}
