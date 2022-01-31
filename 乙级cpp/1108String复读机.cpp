#include<iostream>
#include<map>
int m[256];
using namespace std;
int main() {
	char c;
	scanf("%c", &c);
	while (c != '\n') {
		m[(int)c]++;
		scanf("%c", &c);
	}
	while (m['S'] || m['t'] || m['r'] || m['i'] || m['n'] || m['g']) {
		if (m['S'])
			printf("S"), m['S']--;
		if (m['t'])
			printf("t"), m['t']--;
		if (m['r'])
			printf("r"), m['r']--;
		if (m['i'])
			printf("i"), m['i']--;
		if (m['n'])
			printf("n"), m['n']--;
		if (m['g'])
			printf("g"), m['g']--;
	}
	return 0;
}

