#include<iostream>
using namespace std;
int main(){
	char DAYS[7][4]={
		"MON","TUE","WED","THU","FRI","SAT","SUN"
	};
	string str1,str2,str3,str4;
	int i,j;
	int flag1,flag2,flag3;//flag1��¼���ڼ���flag2��¼��ͷ��flag3��¼���� 
	cin>>str1>>str2>>str3>>str4;
	int max_a=min(str1.length(),str2.length());
    int max_b=min(str3.length(),str4.length());
    
	//��һ��ѭ����ǰ�����ַ����ĵ�һ���ɶԵĴ�д��ĸ 
	for(i=0;i<max_a;i++)
		if(str1[i]>='A'&&str1[i]<='G'&&str1[i]==str2[i]){
			flag1=(int)(str1[i]-'A');
			i++;//����i++�Ǳ�֤��һ��ѭ������һ���ַ���ʼ 
			break;
		}
		
	//�ڶ���ѭ����ǰ�����ַ����ĵڶ��ԣ�����ʱ�� 
	while(i<max_a){
		if(str1[i]>='0'&&str1[i]<='9'&&str1[i]==str2[i]){
			flag2=(int)(str1[i]-'0');
			break;
		}
		else if(str1[i]>='A'&&str1[i]<='N'&&str1[i]==str2[i]){
			flag2=(int)(str1[i]-'A');
			flag2+=10;
			break;
		}
		i++;
	}
	
	for(j=0;j<max_b;j++){
		if(str3[j]>='a'&&str3[j]<='z'&&str3[j]==str4[j]){
			flag3=j;
			break;
		}
		else if(str3[j]>='A'&&str3[j]<='Z'&&str3[j]==str4[j]){
			flag3=j;
			break;
		}
	}
	
	cout<<DAYS[flag1];
    printf(" %d:%.2d",flag2,flag3);
}
