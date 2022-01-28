#include<iostream>
using namespace std;
int top[100];
int bottom[100];
int main() {
	int N;
	int topLow = 1001, bottomHigh = -1001;
	cin >> N;
	int i, j;
	for (i = 0; i < N; i++) {
		cin >> top[i];
		if (topLow > top[i])
			topLow = top[i];
	}
	for (i = 0; i < N; i++) {
		cin >> bottom[i];
		if (bottomHigh < bottom[i])
			bottomHigh = bottom[i];
	}
	if (bottomHigh < topLow)
		cout << "Yes " << topLow - bottomHigh;
	else {
		cout << "No ";
		for (i = 0, j = 0; i < N; i++)
			if (bottom[i] >= topLow)
				if (bottom[i] - topLow + 1 > j)
					j = bottom[i] - topLow + 1;
		cout << j;
	}
	return 0;
}
