#include<iostream>
#include<cmath>
using namespace std;
int main() {
	double r1, p1, r2, p2;
	cin >> r1 >> p1 >> r2 >> p2;
	double r, p;
	r = r1 * r2;
	p = p1 + p2;
	if (r * cos(p) + 0.05 < 0 || r * cos(p) >= 0)
		printf("%.2f", r * cos(p));
	else//����������λС����0�����۱�����λС��ǰ�������������Ǹ����������0.00
		printf("0.00");
	if (r * sin(p) + 0.05 < 0)
		printf("-%.2fi\n", -r * sin(p));
	else if (r * sin(p) >= 0)
		printf("+%.2fi\n", r * sin(p));
	else
		printf("+0.00i\n");
	return 0;
}
