#include<unordered_map>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
unordered_map<int,long long> sell;
bool cmp(int a, int b){
    if(sell[a] == sell[b])
        return a < b;
    return sell[a] > sell[b];    
}

int main(){
    int N, M;
    long long quantity;
    vector<int> id;
    cin>>N>>M;
    int i, j;
    for(i = 0; i < M; i++)
        for(j = 1; j <= N; j++){
            cin>>quantity;
            if(i == 0)
                id.push_back(j);
            sell[j] += quantity;
        }
    sort(id.begin(), id.end(), cmp);
    printf("%d\n%d", sell[id[0]], id[0]);
    for(i = 1; i < id.size() && sell[id[i]] == sell[id[0]]; i++)
        printf(" %d",id[i]);
    return 0;
}
