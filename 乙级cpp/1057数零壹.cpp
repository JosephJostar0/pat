#include<algorithm>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main() {
	string str;
	getline(cin, str);
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	int sum = 0, one = 0, zero = 0, rank = 0;
	int i;
	for (i = 0; i < str.length(); i++)
		if (str[i] >= 'a' && str[i] <= 'z')
			sum += 1 + str[i] - 'a';
	for (rank = 0; pow(2, rank) <= sum; rank++);
	i = rank - 1;
	while (sum && i >= 0) {
		while (sum < pow(2, i))
			i--;
		sum -= pow(2, i);
		one++;
	}
	zero = rank - one;
	cout << zero << ' ' << one << endl;
	return 0;
}
