#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool com(const int& a, const int& b) {
	return a > b;
}

int main() {
	int num;
	vector<int> a;
	cin >> num;
	int up, down;//up是非降序数，down是非升序数 
	int i;

	do {
		for (i = 0; i < 4; i++) {
			a.push_back(num % 10);
			num /= 10;
		}
		sort(a.begin(), a.end(), com);
		for (i = 0, up = 0, down = 0; i < 4; i++) {
			up = up * 10 + a[i];
			down = down * 10 + a[3 - i];
		}
		for (vector<int>::iterator it = a.begin(); it != a.end(); it++) {
			cout << *it;
		}
		cout << " - ";
		for (i = 3; i >= 0; i--) {
			cout << a[i];
		}
		num = up - down;
		if (num) {
			printf(" = %04d\n", num);
			a.clear();
		}
		else {
			printf(" = 0000\n");
			break;
		}
	} while (num != 6174);
	return 0;
}
