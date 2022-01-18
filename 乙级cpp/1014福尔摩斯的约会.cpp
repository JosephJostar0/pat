#include<iostream>
using namespace std;
int main(){
	char DAYS[7][4]={
		"MON","TUE","WED","THU","FRI","SAT","SUN"
	};
	string str1,str2,str3,str4;
	int i,j;
	int flag1,flag2,flag3;//flag1记录星期几，flag2记录钟头，flag3记录分钟 
	cin>>str1>>str2>>str3>>str4;
	int max_a=min(str1.length(),str2.length());
    int max_b=min(str3.length(),str4.length());
    
	//第一次循环找前两个字符串的第一个成对的大写字母 
	for(i=0;i<max_a;i++)
		if(str1[i]>='A'&&str1[i]<='G'&&str1[i]==str2[i]){
			flag1=(int)(str1[i]-'A');
			i++;//这里i++是保证下一次循环从下一个字符开始 
			break;
		}
		
	//第二次循环找前两个字符串的第二对，即找时间 
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
