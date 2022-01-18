#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;
int main() {
	char str[1002];
	cin.getline(str, 1002);
	unsigned int i, j, last = 255;
	int num[256] = { 0 };
	for (i = 0; i < strlen(str); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			j = (int)(str[i] + 'a' - 'A');
		else if (str[i] >= 'a' && str[i] <= 'z')
			j = (int)str[i];
		else
			continue;
		num[j]++;
		if (num[j] > num[last])
			last = j;
		else if (num[j] >= num[last] && last > j)
			last = j;
	}
	cout << (char)last << ' ' << num[last] << endl;
	return 0;
}
