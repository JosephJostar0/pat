#include<iostream>
using namespace std;
int main(){
    int M, num;
    int i, j, k, t;
    cin>>M;
    for(i = 0; i < M; i++){
        cin>>num;
        j = 10;
        while(num % j != num)
            j *= 10;
        for(k = 1; k <= 10; k++){
            t = num * num * k - num;
            if(t % j == 0)
                break;
        }
        t += num;
        if(k <= 10)
            printf("%d %d\n", k, t);
        else
            printf("No\n");
    }
    return 0;
}