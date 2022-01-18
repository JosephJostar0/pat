#include<iostream>
using namespace std;
int main() {
	int N, M;
	int grade[100];
	int answer[100];
	cin >> N >> M;
	int i, j, k, result = 0;
	for (i = 0; i < M; i++)
		cin >> grade[i];
	for (i = 0; i < M; i++)
		cin >> answer[i];
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> k;
			if (k == answer[j])
				result += grade[j];
		}
		cout << result << endl;
		result = 0;
	}
	return 0;
}
