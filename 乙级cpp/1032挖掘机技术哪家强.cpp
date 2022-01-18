#include<iostream>
using namespace std;
int main(){
	int N;
	cin>>N;
	int id,num;
	int* nums = (int*)calloc(N+1,sizeof(int));
	int max=0;
	for(int i=0;i<N;i++){
		cin>>id>>num;
		nums[id]+=num;
		if(nums[id]>=nums[max])
			max=id;
	}
	cout<<max<<' '<<nums[max]<<endl;
}
