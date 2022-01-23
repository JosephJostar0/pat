#include<iostream>
#include<string>
using namespace std;
int main() {
	string pwd, in;
	int N, wrong = 0;
	cin >> pwd >> N;
	getchar();
	while (wrong < N) {
		getline(cin, in);
		if (in == "#")
			break;
		else if (in == pwd) {
			cout << "Welcome in\n";
			break;
		}
		else {
			wrong++;
			cout << "Wrong password: " << in << endl;
		}
		in.clear();
	}
	if (wrong == N)
		cout << "Account locked\n";
	return 0;
}