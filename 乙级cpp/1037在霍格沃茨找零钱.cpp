#include<iostream>
using namespace std;
int main(){
	int pg,ps,pk;//Ӧ�� 
	int ag,as,ak;//ʵ�� 
	scanf("%d.%d.%d",&pg,&ps,&pk);
	scanf("%d.%d.%d",&ag,&as,&ak);
	int pay = pg*17*29+ps*29+pk;
	int harry = ag*17*29+as*29+ak;
	int last = harry-pay;
	bool flag=false;//����������Ǯ��������Ὣflag��Ϊtrue
	if(last<0)
		last=-last,flag=true;
	int g = last/(17*29);
	int s = last%(17*29)/29;
	int k = last%(17*29)%29;
	if(flag)
		cout<<'-';
	printf("%d.%d.%d\n",g,s,k);
}
