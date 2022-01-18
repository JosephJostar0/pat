#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	unsigned int n, i, j, k;
	cin >> n;
	string str;
	string low[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };//0-12
	string high[13] = { "@#$~", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };//1-12
	getchar();
	for (i = 0; i < n; i++) {
		getline(cin, str);
		if (isdigit(str[0])) {
			k = stoi(str);
			if (k / 13)
				cout << high[k / 13];
			if ((k / 13) && (k % 13))
				cout << " ";
			if (k % 13 || k == 0)
				cout << low[k % 13];
		}
		else {
			int p = 0, q = 0;
			string a = str.substr(0, 3), b = "ddd";
			if (str.length() > 4)
				b = str.substr(4, 3);
			for (j = 0; j < 13; j++) {
				if (a == low[j] || b == low[j])
					p = j;
				if (a == high[j])
					q = j;
			}
			cout << p + q * 13;
		}
		cout << endl;
	}
	return 0;
}
