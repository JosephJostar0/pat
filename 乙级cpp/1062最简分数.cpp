#include<iostream>
#include<stdio.h>
using namespace std;

int Euclidean(int a, int b) {
	int i = a, j = b, k;
	while (j) {
		k = i % j;
		i = j;
		j = k;
	}
	return i;
}

int main() {
	int n1, n2, m1, m2, t;
	scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &t);
	int p, q, s;
	bool flag = false;
	if (n1 * m2 > n2 * m1) {
		swap(n1, n2);
		swap(m1, m2);
	}
	p = n1 * t / m1 + 1;
	s = n2 * t / m2;
	if (s * m2 == n2 * t)
		s--;
	while (p <= s) {
		if (Euclidean(p, t) == 1) {
			if (flag)
				cout << ' ';
			printf("%d/%d", p, t);
			flag = true;
		}
		p++;
	}
	cout << endl;
	return 0;
}
