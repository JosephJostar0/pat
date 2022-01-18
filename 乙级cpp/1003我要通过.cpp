#include<iostream>
#include<cstring>
using namespace std;

bool sort(char str[],int begin=0){
	if(str[begin]=='A')
		return str[strlen(str)-1-begin]=='A'
			&& sort(str,begin+1);
	int i;
	if(str[begin]=='P'){
		for(i=0;str[begin+1+i]=='A';i++);
		if((strlen(str)-1-i*begin>begin+i)){
			for(int k=i+begin+2;k<strlen(str);k++)
				if(str[k]!='A')
					return false;
			return str[i+begin+1]=='T'&&str[i+begin]=='A';
		}
	}
	return false;
}

int main(){
	int time;
	char str[101];
	cin>>time;
	for(int i=0;i<time;i++){
		cin>>str;
		if(i)
			cout<<endl;
		if(sort(str))
			cout<<"YES";
		else
			cout<<"NO";
	}
}
