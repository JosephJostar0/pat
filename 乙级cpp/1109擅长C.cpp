#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Letter {
public:
	string line[7];
};

int main() {
	Letter letter[26];
	string str;
	vector<char> v;
	bool flag = false;//控制格式，pat要求回车不能多
	for (int i = 0; i < 26; i++)
		for (int k = 0; k < 7; k++)
			getline(cin, letter[i].line[k]);
	getline(cin, str);
	for (unsigned int i = 0; i < str.size(); i++) {
		while (str[i] - 'A' >= 0 && str[i] - 'Z' <= 0 && i < str.size())
			v.push_back(str[i++]);
		if (v.size() > 0) {
			if (flag)
				cout << endl;
			flag = true;
			for (int j = 0; j < 7; j++) {
				cout << letter[v[0] - 'A'].line[j];
				for (unsigned int k = 1; k < v.size(); k++)
					cout << ' ' << letter[v[k] - 'A'].line[j];
				cout << endl;
			}
			v.clear();
		}
	}
	return 0;
}
