#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

long long divisor(long long a, long long b) {
	long long c = a % b;
	while (c) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

long long multiple(long long a, long long b) {
	long long c = divisor(a, b);
	return (a * b / c);
}

string sort1(long long x1, long long y1, bool ta) {
	char* ddd=new char[9999999999];
	string a, b = "(", c = ")", d = "-";
	if(y1==0){
		sprintf(ddd,"%lld/%lld",x1,y1);
		a=ddd;
		return a;
	}
	int a1 = (int)(x1 / y1);
	int b1 = x1 % y1;
	int p1 = divisor(b1, y1);
	int i, j;

	i = b1 / p1;
	j = y1 / p1;
	if (a1 > 0) {
		if (b1 > 0)
			sprintf(ddd, "%lld %lld/%lld", a1, i, j);
		else
			sprintf(ddd, "%lld", a1);
	}
	else {
		if (i > 0)
			sprintf(ddd, "%lld/%lld", i, j);
		else
			sprintf(ddd, "%lld", i);
	}
	a = ddd;
	delete[]ddd;
	if (!ta && (a1 || b1))
		a = b + d + a + c;
	return a;
}

int main() {
	long long x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	long long z1, z2;
	bool tempa = true, tempb = true, tempz = true;
	string a,b,c;
	
	scanf("%lld/%lld",&x1,&y1);
	scanf("%lld/%lld",&x2,&y2);
	if(x1<0)
		tempa=false,x1=abs(x1);
	if(x2<0)
		tempb=false,x2=abs(x2);

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
	if(z2>0)
		c = sort1(z1, z2, tempz);
	else
		c="Inf";
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
	if(z2>0)
		c = sort1(z1, z2, tempz);
	else
		c = "Ins";
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
