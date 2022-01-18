#include<iostream>
using namespace std;
int main(){
	long long a,b,c;
	int time,i;
	cin>>time;
	for(i=0;i<time;i++){
		cin>>a>>b>>c;
		cout<<"Case #"<<i+1<<":"<<((a-c)>-b?" true\n":" false\n");
	}
	return 0;
}
