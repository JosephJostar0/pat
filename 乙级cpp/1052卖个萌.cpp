#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

void setStr(vector<string>& vec) {
	string str;
	int i, k = -1;
	getline(cin, str);
	for (i = 0; i < str.length(); i++) {
		if (str[i] == '[')
			k = i;
		else if (str[i] == ']')
			vec.push_back(str.substr(k + 1, i - k - 1));
	}
}

int main() {
	string wrong = "Are you kidding me? @\\/@";
	vector<string> hand, eye, mouth;
	setStr(hand);
	setStr(eye);
	setStr(mouth);
	int N;
	int i, j, k, m, n, t;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> j >> k >> m >> n >> t;
		if (j > hand.size() || k > eye.size() || m > mouth.size() || n > eye.size()
			|| t > hand.size() || j < 1 || k < 1 || m < 1 || n < 1 || t < 1) {
			cout << wrong << endl;
			continue;
		}
		cout << hand[j - 1] << "("
			<< eye[k - 1] << mouth[m - 1] << eye[n - 1]
			<< ")" << hand[t - 1] << endl;
	}
	return 0;
}
