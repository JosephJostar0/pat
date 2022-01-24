#include<iostream>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
int M, N, TOL;
int* color;
bool check(int i, int j) {
	int n, k;
	for (n = i == 0 ? i : i - 1; n <= i + 1 && n < N; n++)
		for (k = j == 0 ? j : j - 1; k <= j + 1 && k < M; k++)
			if (n != i || k != j)
				if (abs(color[i * M + j] - color[n * M + k]) <= TOL)
					return false;
	return true;
}

int main() {
	vector<int> v;
	map<int, int> m;
	cin >> M >> N >> TOL;
	color = new int[M * N + 10];
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			cin >> color[i * M + j], m[color[i * M + j]]++;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			if (m[color[i * M + j]] == 1 && check(i, j))
				v.push_back(i * M + j);
	if (v.size() == 0)
		cout << "Not Exist";
	else if (v.size() > 1)
		cout << "Not Unique";
	else
		printf("(%d, %d): %d", 1 + v[0] % M, 1 + v[0] / M, color[v[0]]);
	delete[]color;
	return 0;
}