#include<iostream>
using namespace std;
int main(){
	int N;
	int i;
	int num;
	int a1=0,a2=0,a3=0,a5=0,aa4=0;
	double a4=0;
	bool flag=true,ttt=false;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>num;
		switch(num%5){
			case 0:
				a1+=num%2?0:num;
				break;
			case 1:
				a2+=flag?num:-num;
				flag=!flag;
				ttt=true;
				break;
			case 2:
				a3++;
				break;
			case 3:
				aa4++;
				a4+=num;
				break;
			case 4:
				a5=a5>num?a5:num;
				break;
			default:
				break;
		}
	}
	if(a1)
		cout<<a1<<' ';
	else
		cout<<"N ";
	if(ttt)
		cout<<a2<<' ';
	else
		cout<<"N ";
	if(a3)
		cout<<a3<<' ';
	else
		cout<<"N ";
	if(aa4)
		printf("%.1f ",a4/aa4);
	else
		cout<<"N ";
	if(a5)
		cout<<a5<<endl;
	else
		cout<<"N\n";
}
