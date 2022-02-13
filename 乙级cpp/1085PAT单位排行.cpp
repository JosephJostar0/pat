#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
unordered_map<string,double> in;
unordered_map<string,int> num;
bool cmp(string a,string b){
    if((int)in[a] == (int)in[b]){
        if(num[a] == num[b])
            return a<b;
        return num[a]<num[b];
    }
    return (int)in[a]>(int)in[b];
}

int main(){
    int N;
    char id[7];
    double level;
    string school;
    vector<string> rank;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        cin>>id>>level>>school;
        transform(school.begin(), school.end(), school.begin(), ::tolower);
        if(num[school] == 0)
            rank.push_back(school);
        num[school]++;
        if(id[0] == 'B')
            level = level*2/3;
        else if(id[0] == 'T')
            level = level*3/2;
        in[school] += level;
    }
    sort(rank.begin(), rank.end(), cmp);
    level = 1;
    printf("%d\n%d %s %d %d\n", rank.size(), 1, rank[0].c_str(), (int)in[rank[0]], num[rank[0]]);
    for(int i=1; i<rank.size(); i++){
        if((int)in[rank[i]] == (int)in[rank[i-1]])
            printf("%d %s %d %d\n", (int)level, rank[i].c_str(), (int)in[rank[i]], num[rank[i]]);
        else{
            printf("%d %s %d %d\n", i+1, rank[i].c_str(), (int)in[rank[i]], num[rank[i]]);
            level = i+1;
        }
    }
}