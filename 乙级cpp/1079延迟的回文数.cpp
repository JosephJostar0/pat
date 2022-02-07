#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
bool isPalindrome(string num){
    int n = num.size()-1, m = num.size()/2, i;
    for(i = 0; i<m; i++)
        if(num[i]!=num[n-i])
            return false;
    return true;
}

string plusNum(string a,string b){
    string c;
    int i,j = 0;
    for(i = a.size()-1; i>=0; i--){
        j += a[i] + b[i] - 2*'0';
        c.insert(c.begin(),'0'+j%10);
        j /= 10;
    }
    while(j>0){
        c.insert(c.begin(),'0'+j%10);
        j /= 10;
    }
    return c;
}

int main(){
    string num, alter;
    int time;
    cin>>num;
    if(isPalindrome(num)){
        cout<<num<<" is a palindromic number.\n";
        return 0;
    }
    for(time = 0; time<10; time++){
        cout<<num<<" + ";
        alter = num;
        reverse(alter.begin(),alter.end());
        cout<<alter<<" = ";
        num = plusNum(num,alter);
        cout<<num<<endl;
        if(isPalindrome(num))
            break;
    }
    if(time == 10)
        cout<<"Not found in 10 iterations.\n";
    else
        cout<<num<<" is a palindromic number.\n";
    return 0;
}