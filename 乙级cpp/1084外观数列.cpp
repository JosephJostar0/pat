#include<iostream>
#include<vector>
#include<map>
using namespace std;
string next(string num){
    string n;
    int m, i = 0;
    char flag;
    while(i < num.size()){
        m = 0;
        flag = num[i];
        while(i <num.size() && num[i] == flag){
            m++;
            i++;
        }
        n.push_back(flag);
        n += to_string(m);
    }
    return n;
}

int main(){
    string num;
    int N;
    cin>>num>>N;
    for(int i=1; i<N; i++)
        num = next(num);
    cout<<num<<endl;
}
