#include<iostream>
#include<cmath>
using namespace std;
int M, X, Y;
void print(double a){
    if(a == M)
        cout<<" Ping";
    else if(a > M)
        cout<<" Cong";
    else
        cout<<" Gai";
}

int main(){
    int a, b, c;
    double d;
    cin>>M>>X>>Y;
    for(a=99; a>=10; a--){
        b = a%10*10 + a/10;
        d = (double)b/(double)Y;
        if(d*X == abs(a-b))
            break;
    }
    if(a < 10)
        cout<<"No Solution\n";
    else{
        cout<<a;
        print(a);
        print(b);
        print(d);
    }
    return 0;
}