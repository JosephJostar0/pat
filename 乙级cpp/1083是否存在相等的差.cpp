#include<iostream>
#include<cmath>
#include<map>
using namespace std;
int main(){
    int N, i, j;
    map<int,int> m;
    cin>>N;
    for(i=0; i<N; i++){
        cin>>j;
        j = abs(i-j+1);
        m[j]++;
    }
    for(i=N-1; i>=0; i--)
        if(m.find(i) != m.end())
            if(m[i] > 1)
                printf("%d %d\n",i,m[i]);
    return 0;
}