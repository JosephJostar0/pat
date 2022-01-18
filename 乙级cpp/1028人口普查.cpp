#include<iostream>
using namespace std;
class man{
public:
	int year;
	int month;
	int day;
	string name;
};

void input(man& now){
	cin>>now.name;
	scanf("%d/%d/%d",&now.year,&now.month,&now.day);
}

int cmp(man now,man orther){//>0Ö¸now¸üÄêÇá 
	if(now.year==orther.year){
		if(now.month==orther.month)
			return now.day-orther.day;
		return now.month-orther.month;
	}
	return now.year-orther.year;
}

bool allright(man now,man bottom,man top){
	return (cmp(now,bottom)>=0)&&(cmp(now,top)<=0);
}

int main(){
	man bottom,top;
	man old,young,now;
	int num,useful=0;
	bottom.year=2014-200;
	bottom.month=9;
	bottom.day=6;
	top.year=2014;
	top.month=9;
	top.day=6;
	
	old=top;
	young=bottom;
	cin>>num;
	for(int i=0;i<num;i++){
		input(now);
		if(allright(now,bottom,top)){
			useful++;
			if(cmp(now,young)>0)
				young=now;
			if(cmp(now,old)<0)
				old=now;
		}
	}
	if(useful)
		cout<<useful<<' '<<old.name<<' '<<young.name<<endl;
	else
		cout<<useful<<endl;
	return 0;
}
