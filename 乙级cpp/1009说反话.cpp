#include<iostream>
#include<cstring>
using namespace std;
int main() {
	string str1, str = "";
	do {
		str.append(" ");
		cin >> str1;
		str.append(str1);
	} while (getchar() == ' ');
	int i, k;
	int last = str.length();
	for (i = str.length() - 1; i >= 0; i--) {
		if (str[i] == ' ') {
			for (k = i + 1; k < last; k++)
				cout << str[k];
			last = i;
			if (i > 0)
				cout << ' ';
		}
	}
	cout << endl;
	return 0;
}
