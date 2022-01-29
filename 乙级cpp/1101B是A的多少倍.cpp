#include<iostream>
#include <string>
using namespace std;
int main(){
	string A, ad;
	int D, a, d;
	cin >> A >> D;
	ad = A.substr(A.size() - D);
	ad += A.substr(0, A.size() - D);
	a = stoi(A);
	d = stoi(ad);
	printf("%.2f", (double)d / a);
	return 0;
}