#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Link {
public:
	string address;
	string next;
	int data;
};

int main() {
	string a, b;//两个链表的首地址
	int N;
	vector<Link> v, A, B;
	Link link;
	int i;
	cin >> a >> b >> N;
	for (i = 0; i < N; i++) {
		cin >> link.address >> link.data >> link.next;
		if (link.address == a) {
			A.push_back(link);
			a = link.next;
		}
		else if (link.address == b) {
			B.push_back(link);
			b = link.next;
		}
		else
			v.push_back(link);
	}
	vector<Link>::iterator it = v.begin();//用迭代器实现
	while (a != "-1" || b != "-1") {
		if ((*it).address == a) {
			A.push_back(*it);
			a = (*it).next;
			it = v.begin();
		}
		else if ((*it).address == b) {
			B.push_back(*it);
			b = (*it).next;
			it = v.begin();
		}
		else
			it++;
	}
	if (A.size() < B.size()) {
		v = A;
		A = B;
		B = v;
	}
	for (i = B.size() - 1, it = A.begin(); i >= 0; i--) {
		cout << (*it).address << ' ' << (*it).data << ' ' << (*(it + 1)).address << endl;
		it++;
		cout << (*it).address << ' ' << (*it).data << ' ' << B[i].address << endl;
		it++;
		if (it != A.end())
			cout << B[i].address << ' ' << B[i].data << ' ' << (*it).address << endl;
		else
			cout << B[i].address << ' ' << B[i].data << ' ' << "-1\n";
	}
	if (it != A.end()) {
		cout << (*it).address << ' ' << (*it).data << ' ';
		for (it++; it != A.end(); it++)
			cout << (*it).address << endl << (*it).address << ' ' << (*it).data << ' ';
		cout << -1 << endl;
	}
	return 0;
}