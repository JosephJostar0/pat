#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

void FunC(){
    string line;
    int time,i;
    char flag;
    getline(cin,line);
    for(i=1,flag=line[0],time=1;i<line.size();i++){
        if(line[i]!=flag){
            if(time!=1)
                printf("%d",time);
            printf("%c",flag);
            flag=line[i];
            time=1;
        }
        else
            time++;
    }
    if(time!=1)
        printf("%d",time);
    printf("%c",flag);
}

void FunD(){
    string line;
    int i,time=0,t;
    getline(cin,line);
    for(i=0;i<line.size();i++){
        while(isdigit(line[i])){
            time=time*10+line[i]-'0';
            i++;
        }
        t=0;
        do{
            printf("%c",line[i]);
            t++;
        }while(t<time);
        time=0;
    }
}

int main(){
    char how;
    cin>>how;
    getchar();
    if(how=='C')
        FunC();
    else
        FunD();
    return 0;
}