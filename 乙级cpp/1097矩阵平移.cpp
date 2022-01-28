#include<iostream>
using namespace std;
int a[100][100];
int m[100];
int main() {
	int n, k, x;
	cin >> n >> k >> x;
	int i, j, p, s;
	p = 1;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i % 2 == 0) {
				if (j + p < n)
					cin >> a[i][j + p];
				else
					cin >> s;
				if (j < p)
					a[i][j] = x;
			}
			else
				cin >> a[i][j];
			m[j] += a[i][j];
		}
		if (i % 2 == 0)
			p++;
		if (p > k)
			p = 1;
	}
	cout << m[0];
	for (i = 1; i < n; i++)
		cout << ' ' << m[i];
	return 0;
}

