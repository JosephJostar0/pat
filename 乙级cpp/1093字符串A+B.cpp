#include<unordered_map>
#include<iostream>
#include<string>
using namespace std;
int main(){
    string a, b;
    unordered_map<char,int> flag;
    getline(cin, a);
    getline(cin, b);
    int i;
    for(i = 0; i < a.size(); i++)
        if(flag[a[i]] == 0){
            printf("%c", a[i]);
            flag[a[i]] = 1;
        }
    for(i = 0; i < b.size(); i++)
        if(flag[b[i]] == 0){
            printf("%c", b[i]);
            flag[b[i]] = 1;
        }
    return 0;
}
