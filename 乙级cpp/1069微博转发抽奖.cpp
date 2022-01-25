#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
int main() {
	unsigned int M, N, S;
	map<string, int> m;
	vector<string> v;
	string str;
	unsigned int next;

	cin >> M >> N >> S;
	getchar();
	next = S;
	unsigned int i;
	for (i = 1; i <= M; i++) {
		getline(cin, str);
		if (i == next) {
			if (m[str] == 0) {//the user did not win the price
				next += N;
				v.push_back(str);
				m[str]++;
			}
			else//the user has won the price
				next++;
		}
	}
	for (i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	if (next == S)
		cout << "Keep going...\n";
}