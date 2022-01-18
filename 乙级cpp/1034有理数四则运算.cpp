#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int divisor(int a, int b) {
	int c = a % b;
	while (c) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

int multiple(int a, int b) {
	int c = divisor(a, b);
	return (a * b / c);
}

string sort1(int x1, int y1, bool ta) {
	int a1 = (int)(x1 / y1);
	int b1 = x1 % y1;
	int p1 = divisor(b1, y1);
	int i, j;
	string a, b = "(", c = ")", d = "-";
	char ddd[10000];

	i = b1 / p1;
	j = y1 / p1;
	if (a1 > 0) {
		if (b1 > 0)
			sprintf(ddd, "%d %d/%d", a1, i, j);
		else
			sprintf(ddd, "%d", a1);
	}
	else {
		if (i > 0)
			sprintf(ddd, "%d/%d", i, j);
		else
			sprintf(ddd, "%d", i);
	}
	a = ddd;
	if (!ta && (a1 || b1))
		a = b + d + a + c;
	return a;
}

int main() {
	string a, b, c;
	cin >> a >> b;
	int i;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	int z1, z2;
	bool flag = true, tempa = true, tempb = true, tempz = true;
	for (i = 0; i < a.length(); i++) {
		if (i == 0 && a[i] == '-') {
			tempa = false;
			continue;
		}
		else if (a[i] < '0' || a[i]>'9')
			flag = false, i++;
		if (flag)
			x1 = x1 * 10 + (int)(a[i] - '0');
		else
			y1 = y1 * 10 + (int)(a[i] - '0');
	}
	flag = true;
	for (i = 0; i < b.length(); i++) {
		if (i == 0 && b[i] == '-') {
			tempb = false;
			continue;
		}
		else if (b[i] < '0' || b[i]>'9')
			flag = false, i++;
		if (flag)
			x2 = x2 * 10 + (int)(b[i] - '0');
		else
			y2 = y2 * 10 + (int)(b[i] - '0');
	}
	if (!y1 || !y2) {
		cout << "Inf";
		return 0;
	}

	z2 = multiple(y1, y2);
	a = sort1(x1, y1, tempa);
	b = sort1(x2, y2, tempb);
	
	if (tempa == tempb) {
		z1 = z2 / y1 * x1 + z2 / y2 * x2;
		if (!tempa)
			z1 *= -1;
	}
	else if (tempa)
		z1 = z2 / y1 * x1 - z2 / y2 * x2;
	else
		z1 = -(z2 * x1 / y1 - z2 / y2 * x2);
	if (z1 >= 0)
		tempz = true;
	else
		tempz = false;
	z1 = abs(z1);
	c = sort1(z1, z2, tempz);
	cout << a << " + " << b << " = " << c << endl;

	if (tempa == tempb) {
		z1 = z2 / y1 * x1 - z2 / y2 * x2;
		if (!tempa)
			z1 = -z1;
	}
	else if (tempa)
		z1 = z2 / y1 * x1 + z2 / y2 * x2;
	else
		z1 = -(z2 * x1 / y1 + z2 / y2 * x2);
	if (z1 >= 0)
		tempz = true;
	else
		tempz = false;
	z1 = abs(z1);
	c = sort1(z1, z2, tempz);
	cout << a << " - " << b << " = " << c << endl;

	
	z2 = y1 * y2;
	z1 = x1 * x2;
	if (tempa != tempb)
		tempz = false;
	else
		tempz = true;
	z1 = abs(z1);
	c = sort1(z1, z2, tempz);
	cout << a << " * " << b << " = " << c << endl;

	z2 = y1 * x2;
	z1 = x1 * y2;
	if (tempa != tempb)
		tempz = false;
	else
		tempz = true;
	z1 = abs(z1);
	if (z2 > 0)
		c = sort1(z1, z2, tempz);
	else
		c = "Inf";
	cout << a << " / " << b << " = " << c << endl;
	return 0;
}
