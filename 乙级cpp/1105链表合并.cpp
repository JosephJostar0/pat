#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Link {
public:
	string adress;
	string next;
	int data;
	void set(string a, int d, string n) {
		adress = a;
		data = d;
		next = n;
	}
};

int main() {
	string a, b;//两个链表的首地址
	int N;
	vector<Link> v, A, B;
	Link link;
	string ad, n;
	int d;
	cin >> a >> b >> N;
	for (int i = 0; i < N; i++) {
		cin >> ad >> d >> n;
		link.set(ad, d, n);
		if (ad == a) {
			A.push_back(link);
			a = n;
		}
		else if (ad == b) {
			B.push_back(link);
			b = n;
		}
		else
			v.push_back(link);
	}
	vector<Link>::iterator it = v.begin();//用迭代器实现
	while (v.size() > 0 && (a != "-1" || b != "-1")) {
		while (it != v.end()) {
			if ((*it).adress == a) {
				A.push_back(*it);
				a = (*it).next;
				v.erase(it);
				it = v.begin();
			}
			else if ((*it).adress == b) {
				B.push_back(*it);
				b = (*it).next;
				v.erase(it);
				it = v.begin();
			}
			else
				it++;
		}
		it = v.begin();
	}
	if (A.size() < B.size()) {
		v = A;
		A = B;
		B = v;
	}
	if (A.size() >= 2 * B.size()) {
		v.clear();
		it = A.begin();
		while (B.size() > 0) {
			v.push_back(*it);
			it++;
			v.push_back(*it);
			it++;
			v.push_back(B[B.size() - 1]);
			B.pop_back();
		}
		while (it != A.end()) {
			v.push_back(*it);
			it++;
		}
		for (it = v.begin(); it != (v.begin() + v.size() - 1); it++) {
			cout << (*it).adress << ' ' << (*it).data << ' '
				<< (*(it + 1)).adress << endl;
		}
		cout << (*it).adress << ' ' << (*it).data << ' ' << -1 << endl;
	}
	return 0;
}
