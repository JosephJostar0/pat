#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<map>
using namespace std;
map<string,int> Gp, Gm, Gf, G;
bool cmp(string a,string b){
    if(G[a] == G[b])
        return a < b;
    return G[a] > G[b];
}

int main(){
    int P, M, N;
    vector<string> pass;
    string id;
    cin>>P>>M>>N;
    int i, grade;
    for(i=0; i<P; i++){
        cin>>id>>grade;
        Gp[id] = grade;
    }
    for(i=0; i<M; i++){
        cin>>id>>grade;
        Gm[id] = grade;
    }
    for(i=0; i<N; i++){
        cin>>id>>grade;
        Gf[id] = grade;
        if(Gm.find(id) != Gm.end()){
            if(Gm[id] > Gf[id]){
                G[id] = Gm[id]*4 + Gf[id]*6;
                if(G[id]%10 >= 5)
                    G[id] += 10;
                G[id] /= 10;
            }
            else
                G[id] = Gf[id];
        }
        else
            G[id] = Gf[id];
        if(Gp.find(id) != Gp.end())
            if(Gp[id] >= 200)
                if(G[id] >= 60)
                    pass.push_back(id);
    }
    sort(pass.begin(),pass.end(),cmp);
    for(i=0; i<pass.size(); i++){
        if(Gm.find(pass[i]) == Gm.end())
            Gm[pass[i]] = -1;
        printf("%s %d %d %d %d\n",pass[i].c_str(),Gp[pass[i]],Gm[pass[i]],Gf[pass[i]],G[pass[i]]);
    }
    return 0;
}
