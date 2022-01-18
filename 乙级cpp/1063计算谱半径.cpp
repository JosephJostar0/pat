#include<cmath>
#include<iostream>
using namespace std;
int main() {
	int n;
	int p, q;
	long big = 0, now = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p >> q;
		now = p * p + q * q;
		if (now > big)
			big = now;
	}
	printf("%.2f\n", sqrt(big));
	return 0;
}