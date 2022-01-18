#include<iostream>
#include<string>
using namespace std;

string change(int a, int b, int d) {
	int c = a + b;
	string str = "";
	int i = 0, j;
	while (c > 0) {
		j = c % d;
		c /= d;
		str.insert(0, to_string(j));
	}
	if (!str.length())
		str.insert(0, to_string(0));
	return str;
}

int main() {
	int A, B, D;
	cin >> A >> B >> D;
	string str = change(A, B, D);
	cout << str << endl;
}
