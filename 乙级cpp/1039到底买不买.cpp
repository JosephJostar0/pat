#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int* a=(int*)calloc(256,sizeof(int));
	int* b=(int*)calloc(256,sizeof(int));
	char bunch[1001];
	char want[1001];
	int more=0,less=0;
	cin>>bunch;
	cin>>want; 
	int i;
	for(i=0;i<strlen(bunch);i++)
		a[(int)bunch[i]]++;
	for(i=0;i<strlen(want);i++)
		b[(int)want[i]]++;
	for(i=0;i<256;i++){
		more+=a[i]-b[i];
		if(b[i]>0)
			less+=b[i]>=a[i]?b[i]-a[i]:0;
	}
	if(less>0)
		printf("No %d\n",less);
	else
		printf("Yes %d\n",more);
	return 0;
}
