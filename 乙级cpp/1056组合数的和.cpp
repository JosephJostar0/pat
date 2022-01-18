#include<iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int i, j, k = 0;
	for (i = 0; i < N; i++) {
		cin >> j;
		k += j * (N - 1) * 11;
	}
	cout << k << endl;
	return 0;
}
