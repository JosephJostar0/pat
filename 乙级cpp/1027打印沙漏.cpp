#include<iostream>
using namespace std;

int need(int n) {
	return 2 * n * n - 1;//���ش�ӡһ����2n-1�е�ɳ©����Ҫ�ķ�������
}

void out(int n, char symbol) {
	int k, j;
	for (k = 0; k < n; k++) {//��ӡ������
		for (j = 0; j < k; j++)
			cout << ' ';
		for (j = 0; j < 2 * (n - k) - 1; j++)
			cout << symbol;
		cout << endl;
	}
	for (k = 1; k < n; k++) {//��ӡ��ͷ������
		for (j = 0; j < n - k - 1; j++)
			cout << ' ';
		for (j = 0; j < k * 2 + 1; j++)
			cout << symbol;
		cout << endl;
	}
}

int main() {
	int num;
	char symbol;
	cin >> num >> symbol;
	int i = 1, more, take;
	while (need(i + 1) <= num)
		i++;
	take = need(i);
	more = num - take;
	out(i, symbol);
	cout << more << endl;
	return 0;
}
