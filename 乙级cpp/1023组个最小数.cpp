#include<iostream>
#include<string>
using namespace std;
int main() {
	int num[10];
	int i;
	for (i = 0; i < 10; i++) {
		cin >> num[i];
	}
	for (i = 1; !num[i]; i++);
	cout << i;
	num[i]--;
	for (i = 0; i < 10; i++) {
		while (num[i]) {
			num[i]--;
			cout << i;
		}
	}
	cout << endl;
}
