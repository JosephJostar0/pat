#include<iostream>
using namespace std;
int main() {
	string id, nb, lj;
	int N, top = -1, bottom = 99999, i, x, y;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> id >> x >> y;
		x *= x;
		x += y * y;
		if (x > top) {
			top = x;
			lj = id;
		}
		if (x < bottom) {
			bottom = x;
			nb = id;
		}
	}
	cout << nb << ' ' << lj << endl;
	return 0;
}

