#include<iostream>
using namespace std;
int main() {
	int s;
	cin >> s;
	int i;
	int p, q, m, n;
	int flag1, flag2;
	int j = 0, k = 0;
	for (i = 0; i < s; i++) {
		flag1 = false;
		flag2 = false;
		cin >> p >> q >> m >> n;
		if (p + m == q)
			flag1 = true;
		if (p + m == n)
			flag2 = true;
		if (flag1 == flag2)
			continue;
		else if (flag1)
			k++;
		else
			j++;
	}
	cout << j << ' ' << k << endl;
}