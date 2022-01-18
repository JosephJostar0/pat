#include<iostream>
using namespace std;
int main(){
	int A,B;
	int Da,Db;
	int Pa=0,Pb=0;
	cin>>A>>Da>>B>>Db;
	int i,j;
	i=A;
	while(i>0){
		j=i%10;
		i/=10;
		if(j==Da)
			Pa=Pa*10+Da;
	}
	i=B;
	while(i>0){
		j=i%10;
		i/=10;
		if(j==Db)
			Pb=Pb*10+Db;
	}
	cout<<(Pa+Pb)<<endl;
}
