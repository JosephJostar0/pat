#include<iostream>
using namespace std;
#define CLK_TCK 100
int main() {
	int begin, end, use;
	cin >> begin >> end;
	use = (end - begin + 50) / CLK_TCK;
	int h, min, s;
	h = use / 3600;
	use %= 3600;
	min = use / 60;
	use %= 60;
	s = use;
	printf("%02d:%02d:%02d\n", h, min, s);
}
