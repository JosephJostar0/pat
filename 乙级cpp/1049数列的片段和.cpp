#include<iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	double num;
	int i;
	//double result = 0;
	long long last = 0;//最终结果超出double的范围了
	for (i = 1; i <= N; i++) {
		cin >> num;
		last += (long long)(num * 1000.0) * i * (N - i + 1);
	}
	printf("%.2f\n", last / 1000.0);
	return 0;
}
