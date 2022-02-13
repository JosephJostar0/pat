#include<iostream>
using namespace std;
int main(){
    int N, t=1, i;
    cin>>N;
    for(i=1; i<=N; i++){
        if(i%2==0)
            t++;
        else if(i%3==0)
            t++;
        else if(i%5==0)
            t++;
    }
    cout<<t<<endl;
}