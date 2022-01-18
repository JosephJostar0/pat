#include<iostream>
#include<algorithm>
using namespace std;

class moon{
public:
	double weight;
	double price;
	
	moon(){
		weight=0;
		price=0;
	}
};

bool cmp(moon &a,moon &b){
	return a.price*b.weight>a.weight*b.price;
}

int main(){
	int N,D;
	cin>>N>>D;
	moon cake[1000];
	double max_value=0;
	int i;
	for(i=0;i<N;i++)
		cin>>cake[i].weight;
	for(i=0;i<N;i++)
		cin>>cake[i].price;
	sort(cake,cake+N,cmp);
	for(i=0;i<N&&D>=cake[i].weight;i++){
		D-=cake[i].weight;
		max_value+=(double)cake[i].price;
	}
	if(i<N&&D>0)
		max_value+=(double)(cake[i].price*D)/cake[i].weight;
	printf("%.2f\n",max_value);
}
