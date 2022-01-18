#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char num[1000];
	cin>>num;
	int time[10]={0,0,0,0,0,0,0,0,0,0};
	int i;
	for(i=0;i<strlen(num);i++){
		time[(int)(num[i]-'0')]++;
	}
	for(i=0;i<10;i++)
		if(time[i])
			cout<<i<<":"<<time[i]<<endl;
}
