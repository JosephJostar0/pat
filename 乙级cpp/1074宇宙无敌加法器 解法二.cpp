#include<iostream>
#include<string>
using namespace std;
int main() {
	string table, a, b, out;
	getline(cin, table);
	getline(cin, a);
	getline(cin, b);
	while (a.size() < b.size())
		a.insert(a.begin(), '0');
	while (b.size() < a.size())
		b.insert(b.begin(), '0');
	int i, j, k = table.size() - 1, t = 0;
	for (i = a.size() - 1; i >= 0; i--, k--) {
		t += a[i] + b[i] - 2 * '0';
		if (k < 0 || table[k] == '0')
			j = 10;
		else
			j = (int)(table[k] - '0');
		out.insert(out.begin(), '0' + t % j);
		t /= j;
	}
	while (t > 0) {
		if (k < 0 || table[k] == '0')
			j = 10;
		else
			j = (int)(table[k] - '0');
		out.insert(out.begin(), '0' + t % j);
		t /= j;
	}
	while (out[0] == '0')
		out.erase(out.begin());
	if (out.size() > 0)
		cout << out << endl;
	else
		cout << '0' << endl;
	return 0;
}
