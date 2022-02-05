#include<iostream>
using namespace std;
int main() {
	int N, M;
	int teacher, pro = 0, lite = 101, count = 0, in;
	double student;
	cin >> N >> M;
	int i, k;
	for (i = 0; i < N; i++) {
		count = 0, pro = 0, lite = 101, student = 0;
		cin >> teacher;
		for (k = 1; k < N; k++) {
			cin >> in;
			if (in<0 || in>M)
				continue;
			student += in;
			count++;
			if (in > pro)
				pro = in;
			if (in < lite)
				lite = in;
		}
		student -= pro;
		student -= lite;
		student /= (count - 2);
		student += teacher;
		student /= 2;
		if (student - 0.5 - (int)student >= 0)
			student++;
		printf("%d\n", (int)student);
	}
	return 0;
}
