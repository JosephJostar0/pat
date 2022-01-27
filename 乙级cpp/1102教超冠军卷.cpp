#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Paper {
public:
	string id;
	unsigned int price;
	unsigned int sell;
	unsigned int income;
	void set(string i, unsigned int p, unsigned int s) {
		id = i;
		price = p;
		sell = s;
		income = p * s;
	}
};

bool cmp(Paper a, Paper b) {
	return a.sell > b.sell;
}

bool compare(Paper a, Paper b) {
	return a.income > b.income;
}

int main() {
	int N;
	int p, s;
	string i;
	vector<Paper> v;
	Paper paper;
	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> i >> p >> s;
		paper.set(i, p, s);
		v.push_back(paper);
	}
	sort(v.begin(), v.end(), cmp);
	cout << v[0].id << ' ' << v[0].sell << endl;
	sort(v.begin(), v.end(), compare);
	cout << v[0].id << ' ' << v[0].income << endl;
	return 0;
}
