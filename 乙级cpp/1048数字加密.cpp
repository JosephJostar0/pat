#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int main() {
	char A[101], B[101];
	cin >> A >> B;
	char num[13] = { '0','1','2','3','4','5','6','7','8','9','J','Q','K' };
	int a = strlen(A), b = strlen(B);
	int i, j, k;
	vector<char> last;
	for (i = 1; i <= a && i <= b; i++) {
		j = A[a - i] - '0';
		k = B[b - i] - '0';
		if (i % 2)
			last.push_back(num[(j + k) % 13]);
		else
			last.push_back(num[((k - j) >= 0 ? (k - j) : (k - j + 10))]);
	}
	while (i <= a) {
		j = A[a - i] - '0';
		k = 0;
		if (i % 2)
			last.push_back(num[(j + k) % 13]);
		else
			last.push_back(num[((k - j) >= 0 ? (k - j) : (k - j + 10))]);
		i++;
	}
	while (i <= b) {
		j = 0;
		k = B[b - i] - '0';
		if (i % 2)
			last.push_back(num[(j + k) % 13]);
		else
			last.push_back(num[((k - j) >= 0 ? (k - j) : (k - j + 10))]);
		i++;
	}
	for (i = last.size() - 1; i >= 0; i--)
		cout << last[i];
	cout << endl;
	return 0;
}
