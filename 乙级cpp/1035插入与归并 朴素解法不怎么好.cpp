#include<iostream>
using namespace std;

bool isInsert(int p[], int o[], int n) {
	int i;
	for (i = 1; i < n; i++) {
		if (p[i] < p[i - 1])
			break;
	}
	while (i < n) {
		if (p[i] != o[i])
			return false;
		i++;
	}
	return true;
}

void nextInsert(int p[], int n) {
	cout << "Insertion Sort" << endl;
	int i, k, ex;
	for (i = 1; i < n; i++)
		if (p[i] < p[i - 1])
			break;
	ex = p[i];
	for (k = i - 1; k >= 0 && p[k] > ex; k--)
		if (p[k] > ex)
			p[k + 1] = p[k];
	p[k + 1] = ex;
	cout << p[0];
	for (i = 1; i < n; i++)
		cout << ' ' << p[i];
	cout << endl;
}

void nextMerge(int p[], int n) {
	cout << "Merge Sort" << endl;
	int i, len, ex, k, m, j;
	for (i = 1; i < n; i *= 2) {
		for (j = 0; j < n - i; j += i) {
			ex = p[j];
			for (k = j + 1; k < i + j; k++) {
				if (p[k] < ex)
					break;
				else
					ex = p[k];
			}
			if (k < i + j)
				break;
		}
		if (j < n - i)
			break;
	}
	len = i / 2;
	int a[100];
	k = 0;
	for (i = 0; i < n - 2 * len; i += 2 * len) {
		m = i;
		j = i + len;
		while (m < i + len && j < i + 2 * len) {
			if (p[m] > p[j])
				a[k++] = p[j++];
			else
				a[k++] = p[m++];
		}
		while (m < i + len)
			a[k++] = p[m++];
		while (j < i + 2 * len)
			a[k++] = p[j++];
	}
	m = i;
	j = i + len;
	while (j < n && m < n && m < i + len) {
		if (p[m] > p[j])
			a[k++] = p[j++];
		else
			a[k++] = p[m++];
	}
	while (m < n && m < i + len)
		a[k++] = p[m++];
	while (j < n)
		a[k++] = p[j++];
	cout << a[0];
	for (i = 1; i < n; i++)
		cout << ' ' << a[i];
	cout << endl;
}

int main() {
	int N;
	cin >> N;
	int origin[100];
	int process[100];
	int i;
	for (i = 0; i < N; i++)
		cin >> origin[i];
	for (i = 0; i < N; i++)
		cin >> process[i];
	if (isInsert(process, origin, N))
		nextInsert(process, N);
	else
		nextMerge(process, N);
	return 0;
}
