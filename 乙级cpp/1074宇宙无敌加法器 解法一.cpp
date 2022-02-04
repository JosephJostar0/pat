#include<iostream>
#include<string>
using namespace std;
int main() {
	string table, a, b;
	long long A, B;
	getline(cin, table);
	getline(cin, a);
	getline(cin, b);
	A = (long long)a[0] - (long long)'0';
	B = (long long)b[0] - (long long)'0';
	int i, j, k;
	for (i = 1, k = table.size() - a.size() + 1; i < a.size(); i++, k++) {
		if (k >= 0)
			j = table[k] == '0' ? 10 : (table[k] - '0');
		else
			j = 10;
		A *= (long long)j;
		A += (long long)a[i] - (long long)'0';
	}
	for (i = 1, k = table.size() - b.size() + 1; i < b.size(); i++, k++) {
		if (k >= 0)
			j = table[k] == '0' ? 10 : (table[k] - '0');
		else
			j = 10;
		B *= (long long)j;
		B += (long long)b[i] - (long long)'0';
	}
	A += B;
	b.clear();
	i = table.size() - 1;
	while (A > 0) {
		if (i >= 0)
			j = table[i] - '0' == 0 ? 10 : (table[i] - '0');
		else
			j = 10;
		B = A % (long long)j;
		A /= (long long)j;
		i--;
		b.insert(b.begin(), '0' + (char)B);
	}
	if (b.size() > 0)
		cout << b << endl;
	else
		cout << '0' << endl;
	return 0;
}
