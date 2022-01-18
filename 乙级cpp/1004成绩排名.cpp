#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int num;
	char name_max[11],name_min[11];
	char id_max[11],id_min[11];
	int code_max,code_min;
	char flag1[11],flag2[11];
	int flag3;
	cin>>num;
	cin>>name_max>>id_max>>code_max;
	strcpy(name_min,name_max);
	strcpy(id_min,id_max);
	code_min=code_max;
	for(int i=1;i<num;i++){
		cin>>flag1>>flag2>>flag3;
		if(flag3>code_max){
			code_max=flag3;
			strcpy(id_max,flag2);
			strcpy(name_max,flag1);
		}
		else if(flag3<code_min){
			code_min=flag3;
			strcpy(id_min,flag2);
			strcpy(name_min,flag1);
		}
	}
	cout<<name_max<<' '<<id_max<<endl
		<<name_min<<" "<<id_min<<endl;
}
