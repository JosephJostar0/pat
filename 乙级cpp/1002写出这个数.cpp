#include<iostream>
using namespace std;
int main(){
	string a;
	cin>>a;
	int b=0,d=1,e;
	char c[10][10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	for(int i=0;i<a.length();i++)
		b+=(int)(a[i]-'0');
	while(b/d)
		d*=10;
	d=d/10;
	while(d>1){
		e=(b/d)%10;
		cout<<c[e]<<' ';
		d/=10;
	}
	cout<<c[b%10];
}
