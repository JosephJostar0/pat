#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int N;
	cin >> N;
	vector<int> num;
	int m = 1, n = 1;
	int** out;
	int i, j, k, p, q;
	for (i = 0; i < N; i++) {
		cin >> j;
		num.push_back(j);
	}
	sort(num.begin(), num.end(), cmp);
	for (n = sqrt(N); n >= 1; n--)
		if (N % n == 0) {
			m = N / n;
			break;
		}
	out = new int* [m];
	for (i = 0; i < m; i++)
		out[i] = new int[n];
	i = 0, j = 0, k = 0, p = 0, q = 0;
	while (i < N) {
		while (k < n - 1 - p)
			out[j][k++] = num[i++];
		do {
			out[j++][k] = num[i++];
		} while (j < m - 1 - q);
		while (k > p && i < N)
			out[j][k--] = num[i++];
		while (j > q && i < N)
			out[j--][k] = num[i++];
		p++;
		q++;
		k = p;
		j = q;
	}
	for (i = 0; i < N; i++) {
		cout << out[i / n][i % n];
		if ((i + 1) % n == 0)
			cout << endl;
		else
			cout << ' ';
	}
	delete[]out;
	return 0;
}
