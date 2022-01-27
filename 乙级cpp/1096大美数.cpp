#include<iostream>
#include<vector>
using namespace std;

vector<int> v;

bool binary(int num, int step = 0, int sum = 0, int count = 0) {
	if (step == 4)
		return sum % num == 0;
	if (count == v.size())
		return false;
	sum += v[count];
	if (binary(num, step + 1, sum, count + 1))
		return true;
	sum -= v[count];
	return binary(num, step, sum, count + 1);
}

bool isBeautful(int num) {
	v.clear();
	int top = num;
	for (int i = 1; i <= top; i++)
		if (num % i == 0)
			v.push_back(i);
	if (v.size() < 4)
		return false;
	return binary(num);
}

int main() {
	int K, num;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> num;
		if (isBeautful(num))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
