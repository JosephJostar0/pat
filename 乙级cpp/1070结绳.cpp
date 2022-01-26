#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int N, now = 0;
	vector<int> v;
	cin >> N;
	for (int i = 0, j; i < N; i++) {
		cin >> j;
		v.push_back(j);
	}
	sort(v.begin(), v.end());
	now = v[0];
	for (int i = 1; i < N; i++)
		now = (now + v[i]) / 2;
	cout << now;
	return 0;
}
