#include<iostream>
using namespace std;
int main(){
    int A, B;
    cin>>A>>B;
    A *= B;
    while(A%10 == 0)
        A/=10;
    do{
        cout<<A%10;
        A/=10;
    }while(A>0);
}