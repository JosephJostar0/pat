#include<iostream>
#include<string>
using namespace std;
int main() {
	unsigned int N;
	cin >> N;
	string str;
	int* nums = (int*)calloc(37, sizeof(int));
	unsigned int i, j, k, count = 0;
	for (i = 0; i < N; i++) {
		str.clear();
		cin >> str;
		k = 0;
		for (j = 0; j < str.length(); j++)
			k += str[j] - '0';
		if (!nums[k])
			nums[k]++, count++;
	}
	cout << count << endl;
	for (i = 0; i < 37; i++)
		if (nums[i]) {
			cout << i;
			i++;
			break;
		}
	while (i < 37) {
		if (nums[i])
			cout << ' ' << i;
		i++;
	}
	free(nums);
	return 0;
}