#include<iostream>
using namespace std;
int main() {
	int a, b;
	int i;
	cin >> a >> b;
	if (b)
		cout << a * b << ' ' << b - 1;
	else
		cout << 0 << ' ' << 0;
	while (getchar() == ' ') {
		cin >> a >> b;
		if (b)
			cout << ' ' << a * b << ' ' << b - 1;
	}
	return 0;
}
