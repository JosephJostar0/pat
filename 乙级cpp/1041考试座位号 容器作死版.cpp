#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int witch;

class stu {
public:
	string num;
	int ji;
	int zuo;
	void insert(string i, int j, int k) {
		num = i;
		ji = j;
		zuo = k;
	}
};

bool com(const stu& a, const stu& b) {
	return a.ji > b.ji;
}

template<class T>
bool equal(T a) {
	return a.ji == witch;
}

int main() {
	int N;
	cin >> N;
	vector<stu> all;
	vector<stu>::iterator iter;
	stu s;
	int j, k, q;
	string i;
	for (q = 0; q < N; q++) {
		cin >> i >> j >> k;
		s.insert(i, j, k);
		all.push_back(s);
	}
	sort(all.begin(), all.end(), com);
	int M;
	cin >> M;
	for (q = 0; q < M; q++) {
		cin >> witch;
		iter = find_if(all.begin(), all.end(), equal<stu>);
		cout << (*iter).num << ' ' << (*iter).zuo << endl;
	}
	return 0;
}