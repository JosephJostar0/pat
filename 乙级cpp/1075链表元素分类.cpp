#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main() {
	int N, K, need;
	int ad, da, ne;
	vector<int> wait[2];
	map<int, int> Data;
	map<int, int>Next;
	scanf("%d %d %d", &need, &N, &K);
	int i, k;
	for (i = 0; i < N; i++) {
		scanf("%d %d %d", &ad, &da, &ne);
		Data[ad] = da;
		Next[ad] = ne;
	}
	bool flag = false;
	while (need != -1) {
		if (Data[need] < 0) {
			if (flag)
				printf("%05d\n", need);
			flag = true;
			printf("%05d %d ", need, Data[need]);
		}
		else if (Data[need] <= K)
			wait[0].push_back(need);
		else
			wait[1].push_back(need);
		need = Next[need];
	}
	for (k = 0; k < 2; k++)
		for (i = 0; i < wait[k].size(); i++) {
			if (flag)
				printf("%05d\n", wait[k][i]);
			flag = true;
			printf("%05d %d ", wait[k][i], Data[wait[k][i]]);
		}
	printf("-1\n");
	return 0;
}
