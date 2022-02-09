#include<iostream>
#include<string>
using namespace std;
int main() {
	string line;
	int N, i, j, k;
	bool digit, letter;
	cin >> N;
	getchar();
	for (i = 0; i < N; i++) {
		digit = true;
		letter = true;
		getline(cin, line);
		j = line.size();
		if (j < 6) {
			cout << "Your password is tai duan le.\n";
			continue;
		}
		for (k = 0; k < j; k++) {
			if (line[k] >= 'a' && line[k] <= 'z')
				letter = false;
			else if (line[k] >= 'A' && line[k] <= 'Z')
				letter = false;
			else if (line[k] >= '0' && line[k] <= '9')
				digit = false;
			else if (line[k] != '.') {
				cout << "Your password is tai luan le.\n";
				break;
			}
		}
		if (k == j) {
			if (digit)
				cout << "Your password needs shu zi.\n";
			else if (letter)
				cout << "Your password needs zi mu.\n";
			else
				cout << "Your password is wan mei.\n";
		}
	}
	return 0;
}

