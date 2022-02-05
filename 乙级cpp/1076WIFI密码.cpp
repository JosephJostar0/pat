#include<iostream>
#include<cstring>
using namespace std;
int main() {
	int N;
	char line[18];
	cin >> N;
	int i, j;
	getchar();
	for (i = 0; i < N; i++) {
		cin.getline(line, 18);
		for (j = 2; j < strlen(line); j++)
			if (line[j] == 'T')
				break;
		j = line[j - 2] - 'A' + 1;
		cout << j;
	}
	return 0;
}
