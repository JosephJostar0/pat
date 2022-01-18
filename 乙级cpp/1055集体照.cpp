#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

class Man {
public:
	int height;
	string name;
	Man() {
		height = 0;
	}
};

bool cmp(Man a, Man b) {
	if (a.height == b.height)
		return strcmp(a.name.c_str(), b.name.c_str()) <= 0;
	return a.height > b.height;
}

if(a���>b���)
	����
else if(a���<b���)
	����a, b
else
	��������

void print(vector<Man> mans, int begin, int len) {//end��ȡ��beginȡ
	int i = begin + 2, j;
	j = len % 2 ? len - 2 + begin : len - 1 + begin;
	while (j > begin) {
		cout << mans[j].name << ' ';
		j -= 2;
	}
	cout << mans[begin].name;
	while (i < begin + len) {
		cout << ' ' << mans[i].name;
		i += 2;
	}
	cout << endl;
}

int main() {
	Man man;
	vector<Man> mans;
	int N, K;
	cin >> N >> K;
	int i, j, k;
	for (i = 0; i < N; i++) {
		cin >> man.name >> man.height;
		mans.push_back(man);
	}
	sort(mans.begin(), mans.end(), cmp);
	j = N / K;//ÿһ�ж�����
	k = N - j * K + j;//���һ�ж�����
	print(mans, 0, k);
	for (i = 0; i < K - 1; i++)
		print(mans, k + i * j, j);
	return 0;
}
