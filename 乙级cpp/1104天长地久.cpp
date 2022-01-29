#include<iostream>
#include<string>
#include<cmath>
#include<map>
using namespace std;
string num;
int N, K, m;
bool ans = false;
map<int, int> prime;
int euc[90][90];

bool isPrime(int p) {
	int q = sqrt(p);
	for (int i = 2; i <= q; i++)
		if (p % i == 0)
			return false;
	return p > 1;
}

int euclid(int s, int n) {
	int t;
	while (s % n > 0) {
		t = s % n;
		s = n;
		n = t;
	}
	return n;
}

void dfs(int n, int sum1 = 0, int step = 0) {
	if (step == K - 1) {
		int i, sum2 = sum1 + 1;
		sum1 += 9;
		if (sum1 != m || num[0] == '0')
			return;
		for (i = 0; i < step && num[step - i - 1] == '9'; i++)
			sum2 -= 9;
		if (sum2 != n)
			return;
		ans = true;
		printf("%d %s9\n", n, num.c_str());
		return;
	}
	for (int i = 0; i <= 9 && sum1 + i <= m; i++) {
		num.push_back('0' + i);
		dfs(n, sum1 + i, step + 1);
		num.pop_back();
	}
}

bool everLast() {
	if (K * 9 - m <= 0)
		return false;
	int n, p;
	bool flag = false;
	for (n = (m + 1) % 9; n < m; n += 9) {
		p = euc[m][n];
		if (p > 2 && prime[p]) {
			ans = false;
			dfs(n);
			if (ans)
				flag = true;
		}
	}
	return flag;
}

int main() {
	for (int i = 1; i < 90; i++) {
		if (isPrime(i))
			prime[i]++;
		for (int k = 3; k <= i - 8; k++)
			euc[i][k] = euclid(i, k);
	}
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &K, &m);
		printf("Case %d\n", i);
		if (!everLast())
			printf("No Solution\n");
	}
	return 0;
}
