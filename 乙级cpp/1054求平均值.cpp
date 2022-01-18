#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

double toDigit(string& str) {
	int i, j;
	double result = 0;
	i = str[0] == '-' ? 1 : 0;
	while (i < str.length() && str[i] != '.') {
		if (str[i] > '9' || str[i] < '0') {
			i = str.length();
			result = 1999;
			break;
		}
		result = result * 10 + str[i] - '0';
		i++;
	}
	j = i + 1;
	while (j < str.length()) {
		if (str[j] > '9' || str[j] < '0') {
			result = 1999;
			break;
		}
		result += (double)((double)str[j] - (double)'0') / pow(10, j - i);
		j++;
	}
	if (j - i > 3 || result > 1000)
		return 1999;
	return str[0] == '-' ? -result : result;
}

int main() {
	string wrong = "The average of 0 numbers is Undefined";
	string dis = " is not a legal number";
	string error = "ERROR: ";
	string str;
	int N;
	int i, j, k;
	int used = 0;
	double last = 0, temp;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> str;
		temp = toDigit(str);
		if (temp == 1999) {
			cout << error << str << dis << endl;
			continue;
		}
		used++;
		last += temp;
	}
	if (used == 0)
		cout << wrong << endl;
	else if (used > 1)
		printf("The average of %d numbers is %.2f\n", used, last / (double)used);
	else
		printf("The average of %d number is %.2f\n", used, last / (double)used);
	return 0;
}
