#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string, int> nums;
int main() {
	int N, M, K, count = 0, thing = 0;
	string name, num;
	bool flag = true;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		nums[num]++;
	}
	for (int i = 0; i < N; i++) {
		flag = true;
		cin >> name >> K;
		for (int j = 0; j < K; j++) {
			cin >> num;
			if (nums[num]) {
				if (flag) {
					count++;
					cout << name << ":";
					flag = false;
				}
				cout << ' ' << num;
				thing++;
			}
		}
		if (!flag)
			cout << endl;
	}
	printf("%d %d\n", count, thing);
	return 0;
}

