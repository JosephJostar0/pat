#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

bool cmp(string a, string b) {
	int aYear = stoi(a.substr(6, 4));
	int aMon = stoi(a.substr(10, 2));
	int aDay = stoi(a.substr(12, 2));
	int bYear = stoi(b.substr(6, 4));
	int bMon = stoi(b.substr(10, 2));
	int bDay = stoi(b.substr(12, 2));
	if (aYear == bYear) {
		if (aMon == bMon)
			return aDay < bDay;
		return aMon < bMon;
	}
	return aYear < bYear;
}

int main() {
	int N, M;
	string str;
	string old = "000000999912310000";
	map<string, int> alumnus;
	vector<string> v;
	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> str;
		alumnus[str]++;
	}
	cin >> M;
	for (int m = 0; m < M; m++) {
		cin >> str;
		if (alumnus[str])
			v.push_back(str);
		if (cmp(str, old))
			old = str;
	}
	cout << v.size() << endl;
	if (v.size()) {
		sort(v.begin(), v.end(), cmp);
		cout << v[0] << endl;
	}
	else
		cout << old << endl;
	return 0;
}
