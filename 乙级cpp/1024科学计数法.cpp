#include<iostream>
#include<string>
using namespace std;
int main() {
	string sci, num = "", cover = "";
	int cloth;
	cin >> sci;
	int i, pointPlace;
	i = sci.find('E');
	num.append(sci, 0, i);
	cover.append(sci, i + 1);
	pointPlace = num.find('.');
	cloth = stoi(cover);
	num.replace(pointPlace, 1, "");
	if (cloth >= 0) {
		if (num.length() <= pointPlace + cloth)
			while (num.length() < cloth + pointPlace)
				num.append("0");
		else
			num.insert(pointPlace + cloth, ".");
	}
	else {
		if (pointPlace + cloth > 1)
			num.insert(pointPlace + cloth, ".");
		else {
			for (i = 0; i + pointPlace + cloth <= 1; i++)
				num.insert(1, "0");
			num.insert(pointPlace + i + cloth, ".");
		}
	}
	if (num.find('+') == 0)
		num.replace(0, 1, "");
	cout << num << endl;
	return 0;
}
