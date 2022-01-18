#include<iostream>
#include<cstring>
using namespace std;
int main() {
	char origin[81], fact[81];
	cin.getline(origin, 81);
	cin.getline(fact, 81);
	int* num = (int*)calloc(256, sizeof(int));
	int* flag = (int*)calloc(256, sizeof(int));
	for (int i = 0; i < strlen(fact); i++)
		num[(int)fact[i]]--;
	for (int i = 0; i < strlen(origin); i++) {
		num[(int)origin[i]]++;
		if (num[(int)origin[i]] > 0) {
			if (origin[i] >= 'a' && origin[i] <= 'z')
				origin[i] -= 'a' - 'A';
			if (flag[(int)origin[i]] == 0)
				cout << origin[i];
			flag[(int)origin[i]] = 1;
		}
	}
	cout << endl;
	return 0;
}
