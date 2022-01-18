#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int N;
	vector<int> ride;
	cin >> N;
	int i, j;
	for (i = 0; i < N; i++) {
		cin >> j;
		ride.push_back(j);
	}
	sort(ride.begin(), ride.end());
	for (i = 0; i < N; i++)
		if (N - i <= ride[i] - 1)
			break;
	cout << N - i << endl;
	return 0;
}
