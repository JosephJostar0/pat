#include<iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int* team = (int*)calloc(N, sizeof(int));
	int i, j, k;
	int s;
	int max = 0;
	for (s = 0; s < N; s++) {
		scanf("%d-%d %d", &i, &j, &k);
		team[i] += k;
		if (team[i] > team[max])
			max = i;
	}
	cout << max << ' ' << team[max] << endl;
	free(team);
	return 0;
}