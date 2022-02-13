#include<unordered_map>
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N, M, K;
    string a, b;
    bool ok;
    unordered_map<string,vector<string>> dis;
    unordered_map<string,int> list;
    cin>>N>>M;
    int i, j, t;
    for(i = 0; i < N; i++){
        cin>>a>>b;
        dis[a].push_back(b);
        dis[b].push_back(a);
    }
    for(i = 0; i < M; i++){
        cin>>K;
        list.clear();
        ok = true;
        for(j = 0; j < K; j++){
            cin>>a;
            if(ok){
                list[a] = 1;
                for(t = 0; t < dis[a].size(); t++)
                    if(list[dis[a][t]] == 1){
                        ok = false;
                        break;
                    }
            }
        }
        if(ok)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}