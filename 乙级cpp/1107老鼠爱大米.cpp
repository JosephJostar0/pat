#include<iostream>
using namespace std;
int main() {
	int N, M;
	bool flag = false;
	cin >> N >> M;
	int i, j, k, big = 0, fat = 0;
	for (i = 0; i < N; i++) {
		for (j = 0, fat = 0; j < M; j++) {
			cin >> k;
			if (k > fat)
				fat = k;
		}
		if (fat > big)
			big = fat;
		if (flag)
			printf(" %d", fat);
		else
			printf("%d", fat);
		flag = true;
	}
	printf("\n%d", big);
	return 0;
}

