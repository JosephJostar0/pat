#include<iostream>
#include<vector>
using namespace std;
int main() {
	int N, M;
	int* single = (int*)calloc(1000000, sizeof(int));
	int* match = (int*)malloc(1000000*sizeof(int));
	int i, j, k;
	vector<int> vs;
	for (i = 0; i < 1000000; i++)
		match[i] = -1;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> j >> k;
		match[j] = k;
		match[k] = j;
	}
	cin >> M;
	for (i = 0; i < M; i++) {
		cin >> j;
		single[j]++;
	}
	for (i = 0; i < 1000000; i++)
		if (single[i] == 1) {
			if (match[i] >= 0) {
				if (single[match[i]] == 0)
					vs.push_back(i);
			}
			else
				vs.push_back(i);
		}
	cout << vs.size() << endl;
	if (vs.size())
		printf("%05d", vs[0]);
	for (i = 1; i < vs.size(); i++)
		printf(" %05d", vs[i]);
	free(single);
	free(match);
	return 0;
}