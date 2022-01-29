#include<iostream>
#include<cmath>
using namespace std;
long long isLuck(long long i) {
	long long j = powl(i, 3) - powl(i - 1, 3);
	if (powl((long long)sqrtl(j), 2) != j)
		return i;
	j = sqrtl(j);
	long long k = 1;
	long long p = powl(k, 2) + powl(k - 1, 2);
	while (p < j) {
		k++;
		p = powl(k, 2) + powl(k - 1, 2);
	}
	return p == j ? k : i;
}

int main() {
	long long m, n;
	bool flag = true;
	cin >> m >> n;
	for (long long i = m, k = 0; i <= n; i++) {
		k = isLuck(i);
		if (k != i) {
			flag = false;
			cout << i << ' ' << k << endl;
		}
	}
	if (flag)
		cout << "No Solution";
	return 0;
}