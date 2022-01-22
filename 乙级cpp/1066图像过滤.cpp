#include<iostream>
#include<vector>
using namespace std;
int main() {
	int M, N, A, B, ex;
	vector<int> map;
	cin >> M >> N >> A >> B >> ex;
	for (int i = 0, j; i < M * N; i++) {
		cin >> j;
		if (j >= A && j <= B)
			j = ex;
		map.push_back(j);
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			printf("%03d", map[i * N + j]);
			if (j != N - 1)
				cout << ' ';
		}
		cout << endl;
	}
	return 0;
}