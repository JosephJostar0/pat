#include<iostream>
#include<string>
#include<cmath>
#include<map>
using namespace std;
string num;
unsigned int N, K, m;
bool ans;

bool isPrime(unsigned int p) {
	int q = sqrt(p);
	for (int i = 2; i <= q; i++)
		if (p % i == 0)
			return false;
	return true;
}

int euclid(unsigned int s, unsigned int n) {
	int t;
	if (n < 1)
		return 0;
	while (s % n > 0) {
		t = s % n;
		s = n;
		n = t;
	}
	return n;
}

void dfs(unsigned int n, unsigned int sum1, unsigned int line) {
	if (num.size() == K - line) {
		if (sum1 != m || num[0] == '0' || num[K - line - 1] == '9')
			return;
		ans = true;
		printf("%d %s", n, num.c_str());
		for (unsigned int i = 0; i < line; i++)
			printf("9");
		printf("\n");
		return;
	}
	for (int i = 0; i <= 9 && sum1 + i <= m; i++) {
		num.push_back('0' + i);
		dfs(n, sum1 + i, line);
		num.pop_back();
	}
}

bool everLast() {
	if (K * 9 - m <= 0)
		return false;
	unsigned int n, p;
	bool flag = false;
	for (n = (m + 1) % 9; n < m; n += 9) {
		p = euclid(m, n);
		if (p > 2 && isPrime(p)) {
			ans = false;
			num.clear();
			p = (m + 1 - n) / 9;
			dfs(n, p * 9, p);
			if (ans)
				flag = true;
		}
	}
	return flag;
}

int main() {
	scanf("%d", &N);
	for (unsigned int i = 1; i <= N; i++) {
		scanf("%d%d", &K, &m);
		printf("Case %d\n", i);
		if (!everLast())
			printf("No Solution\n");
	}
	return 0;
}
