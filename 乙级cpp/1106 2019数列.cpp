#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int> v = { 2,0,1,9 };
	int sum = v[0] + v[1] + v[2] + v[3];
	int n, i;
	cin >> n;
	for (i = 0; i < n && i < 4; i++)
		printf("%d", v[i]);
	while (i < n) {
		v[i] = sum % 10;
		sum -= v[i - 4];
		sum += v[i];
		printf("%d", v[i]);
		i++;
	}
	return 0;
}
