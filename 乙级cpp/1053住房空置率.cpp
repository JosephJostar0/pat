#include<iostream>
using namespace std;
int main() {	
	int N, D;
	double e;
	cin >> N >> e >> D;
	int i, j, k, q = 0;
	double p;
	double m = 0, n = 0;//m可能空置 n空置
	for (i = 0; i < N; i++) {
		cin >> k;
		for (j = 0, q = 0; j < k; j++) {
			cin >> p;
			if (p < e)
				q++;//q用来记录低于e的天数有几天
		}
		if (q * 2 > k) {
			if (k > D)
				n++;
			else
				m++;
		}
	}
	printf("%.1f%% %.1f%%\n", (m * 100 / N), (n * 100 / N));
	return 0;
}
