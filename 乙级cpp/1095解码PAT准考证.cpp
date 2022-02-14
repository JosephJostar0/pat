#include<unordered_map>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int N, M, grade;
unordered_map<string, int> score, num;
vector<string> mate;
string no, how;
bool cmp1(string a,string b){
    if(score[a] == score[b])
        return a < b;
    return score[a] > score[b];
}

bool cmp3(string a,string b){
    if(num[a] == num[b])
        return a < b;
    return num[a] > num[b];
}

void Fun1(){
    int t;
    vector<string> out;
    for(t = 0; t < mate.size(); t++)
        if(mate[t].substr(0, 1) == how)
            out.push_back(mate[t]);
    sort(out.begin(), out.end(), cmp1);
    for(t = 0; t < out.size(); t++)
        printf("%s %d\n", out[t].c_str(), score[out[t]]);
    if(out.size() == 0)
        printf("NA\n");
}

void Fun2(){
    int t, num = 0, level = 0;
    for(t = 0; t < mate.size(); t++)
        if(mate[t].substr(1, 3) == how)
            num++, level += score[mate[t]];
    if(num)
        printf("%d %d\n", num, level);
    else
        printf("NA\n");
}

void Fun3(){
    int t;
    num.clear();
    vector<string> room;
    for(t = 0; t < mate.size(); t++)
        if(mate[t].substr(4, 6) == how)
            num[mate[t].substr(1, 3)]++;
    for(auto it : num)
        room.push_back(it.first);
    sort(room.begin(), room.end(), cmp3);
    for(t = 0; t < room.size(); t++)
        printf("%s %d\n", room[t].c_str(), num[room[t]]);
    if(room.size() == 0)
        printf("NA\n");
}

int main(){
    cin>>N>>M;
    int i, kind;
    for(i = 0; i < N; i++){
        cin>>no>>grade;
        score[no] = grade;
        mate.push_back(no);
    }
    for(i = 0; i < M; i++){
        cin>>kind>>how;
        printf("Case %d: %d %s\n", i + 1, kind, how.c_str());
        if(kind == 1)
            Fun1();
        else if(kind == 2)
            Fun2();
        else
            Fun3();
    }
    return 0;
}
