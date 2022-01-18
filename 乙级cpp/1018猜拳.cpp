#include<iostream>
using namespace std;

int VS(char w1,char w2,int c[2],int j[2],int b[2]){
	if(w1==w2)
		return 0;
	switch(w1){
		case 'C':
			if(w2=='J'){
				c[0]++;
				return 1;
			}
			else{
				b[1]++;
				return -1;
			}
		case 'J':
			if(w2=='C'){
				c[1]++;
				return -1;
			}
			else{
				j[0]++;
				return 1;
			}
		case 'B':
			if(w2=='C'){
				b[0]++;
				return 1;
			}
			else{
				j[1]++;
				return -1;
			}
	}
}

int main(){
	int N;
	int win1=0,win2=0;
	int c[2]={0,0},j[2]={0,0},b[2]={0,0};
	int i,k;
	char w1,w2;
    cin>>N;
	for(i=0;i<N;i++){
		cin>>w1>>w2;
		k=VS(w1,w2,c,j,b);
		switch(k){
			case 1:
				win1++;
				break;
			case -1:
				win2++;
				break;
			default:
				break;
		}
	}
	
	if(b[0]>=c[0]&&b[0]>=j[0])
		w1='B';
	else if(c[0]>=b[0]&&c[0]>=j[0])
		w1='C';
	else
		w1='J';
	
	if(b[1]>=c[1]&&b[1]>=j[1])
		w2='B';
	else if(c[1]>=b[1]&&c[1]>=j[1])
		w2='C';
	else
		w2='J';
	
	cout<<win1<<' '<<(N-win1-win2)<<' '<<win2<<endl
		<<win2<<' '<<(N-win1-win2)<<' '<<win1<<endl
		<<w1<<' '<<w2<<endl;
	
}
