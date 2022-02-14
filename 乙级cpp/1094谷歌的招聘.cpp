#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
bool isPrime(long long n){
    long long i;
    for(i = 3; i * i <= n; i += 2)
        if(n % i == 0)
            return false;
    return n >= 2;
}

int main(){
    int L, K;
    int i;
    long long n;
    string line, num;
    cin>>L>>K>>line;
    for(i = 0; i <= L - K; i++){
        num = line.substr(i, K);
        n = stol(num);
        if(n == 2 || (n % 2 != 0 && isPrime(n)))
            break;
    }
    if(i > L - K)
        printf("404\n");
    else
        printf("%s\n",num.c_str());
    return 0;
}
