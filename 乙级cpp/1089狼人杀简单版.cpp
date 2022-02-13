#include<iostream>
#include<cmath>
using namespace std;
int say[101];
int main(){
    int N, wrong, i, j, k;
    bool flag;
    cin>>N;
    for(i = 1; i <= N; i++)
        cin>>say[i];
    for(i = 1; i <= N; i++){
        for(j = i + 1 ; j <= N; j++){
            wrong = 0;
            flag = false;
            for(k = 1; k <= N; k++){
                if(say[k] < 0 && i != abs(say[k]) && j != abs(say[k])){
                    wrong++;
                    if(k == i || k == j)
                        flag = !flag;
                }
                if(say[k] == j || say[k] == i){
                    wrong++;
                    if(k == i || k == j)
                        flag = !flag;
                }
                if(wrong > 2)
                    break;
            }
            if(flag && wrong == 2)
                break;
        }
        if(j <= N)
            break;
    }
    if(i <= N && j <= N)
        cout<<i<<' '<<j<<endl;
    else
        cout<<"No Solution\n";
    return 0;
}