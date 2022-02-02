#include<iostream>
using namespace std;
int main() {
	int T, K;
	int n1, b, t, n2, x;
	cin >> T >> K;
	x = T;
	for (int i = 0; i < K; i++) {
		cin >> n1 >> b >> t >> n2;
		if (t > x) {
			printf("Not enough tokens.  Total = %d.\n", x);
			continue;
		}
		if ((b > 0) == (n2 > n1)) {
			x += t;
			printf("Win %d!  Total = %d.\n", t, x);
		}
		else {
			x -= t;
			printf("Lose %d.  Total = %d.\n", t, x);
			if (x == 0) {
				printf("Game Over.\n");
				break;
			}
		}
	}
	return 0;
}

