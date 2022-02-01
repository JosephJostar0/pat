#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Node {
public:
	string address;
	int data;
	string next;
};
int main() {
	int K, N;
	string need;
	Node node;
	vector<Node> v, link;
	stack<vector<Node>> s;
	cin >> need >> N >> K;
	int i;
	bool flag = false;
	for (i = 0; i < N; i++) {
		cin >> node.address >> node.data >> node.next;
		if (node.address == need) {
			link.push_back(node);
			need = node.next;
			if (link.size() == K) {
				s.push(link);
				link.clear();
			}
		}
		else
			v.push_back(node);
	}
	i = 0;
	while (need != "-1") {
		if (v[i].address == need) {
			link.push_back(v[i]);
			need = v[i].next;
			if (link.size() == K) {
				s.push(link);
				link.clear();
			}
			v.erase(v.begin() + i);
			i = -1;
		}
		i++;
	}
	if (link.size() > 0)
		s.push(link);
	while (s.size() > 0) {
		link = s.top();
		s.pop();
		for (i = 0; i < link.size(); i++) {
			if (flag)
				cout << link[i].address << "\n";
			else
				flag = true;
			cout << link[i].address << ' ' << link[i].data << ' ';
		}
	}
	cout << "-1\n";
	return 0;
}

