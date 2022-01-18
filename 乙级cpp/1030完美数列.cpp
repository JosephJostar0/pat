#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	long long N, p;
	cin >> N >> p;
	vector<long long> a(N);
	int i, j;
	int temp = 0, last = 0;
	for (i = 0; i < N; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	for (i = 0; i < N - last; i++) {
		for (j = i + temp; j < N; j++) {
			if (a[j] <= a[i] * p) {
				temp = j - i + 1;
				if (temp > last)
					last = temp;
			}
			else
				break;
		}
	}
	cout << last << endl;
}
