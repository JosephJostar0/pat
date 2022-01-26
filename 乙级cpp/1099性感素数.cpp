#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(long n) {
	if (n < 2)
		return false;
	int m = sqrt(n);
	for (int i = 2; i <= m; i++)
		if (n % i == 0)
			return false;
	return true;
}

int isSex(long n) {
	if (isPrime(n)) {
		if (isPrime(n - 6))
			return -6;
		else if (isPrime(n + 6))
			return 6;
		else
			return 0;
	}
	return 0;
}

int main() {
	long N;
	cin >> N;
	int s = isSex(N);
	if (s != 0)
		cout << "Yes\n" << N + s << endl;
	else {
		cout << "No\n";
		while (s == 0)
			s = isSex(++N);
		cout << N << endl;
	}
	return 0;
}
