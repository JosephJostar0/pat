#include<iostream>
using namespace std;
int main() {
	int n;
	char s;
	cin >> n >> s;
	int i, j;
	for (i = 0; i < n; i++)
		cout << s;
	cout << endl;
	for (i = 0; i < (n + 1) / 2 - 2; i++) {
		cout << s;
		for (j = 0; j < n - 2; j++)
			cout << ' ';
		cout << s << endl;
	}
	for (i = 0; i < n; i++)
		cout << s;
	cout << endl;
	return 0;
}