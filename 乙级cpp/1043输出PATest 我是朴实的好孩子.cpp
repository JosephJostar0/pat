#include<iostream>
#include<cstring> 
using namespace std;
int main(){
	char str[10004];
	cin>>str;
	int i;
	int P=0,A=0,T=0,e=0,s=0,t=0;
	for(i=0;i<strlen(str);i++){
		switch(str[i]){
			case 'P':
				P++;
				break;
			case 'A':
				A++;
				break;
			case 'T':
				T++;
				break;
			case 'e':
				e++;
				break;
			case 's':
				s++;
				break;
			case 't':
				t++;
				break;
			default:
				break;
		}
	}
	while(P||A||T||e||s||t){
		if(P){
			cout<<'P';
			P--;
		}
		if(A){
			cout<<'A';
			A--;
		}
		if(T){
			cout<<'T';
			T--;
		}
		if(e){
			cout<<'e';
			e--;
		}
		if(s){
			cout<<'s';
			s--;
		}
		if(t){
			cout<<'t';
			t--;
		}
	}
	cout<<endl;
	return 0;
}
