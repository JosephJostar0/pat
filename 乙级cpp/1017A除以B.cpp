#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char A[1000];
	int B,R;
	char Q[1000];
	int num;
	int i;
	cin>>A>>B;
	num=(int)(A[0]-'0');
	if(num/B)
		cout<<(num/B);
	num%=B;
	for(i=1;i<strlen(A);i++){
		num=num*10+(int)(A[i]-'0');
		cout<<(num/B);
		num%=B;
	}
    if(strlen(A)==1&&num<B)
        cout<<0;
	cout<<' '<<num<<endl;
}
