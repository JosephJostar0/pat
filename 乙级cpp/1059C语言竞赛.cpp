#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;

class Member {
public:
	char id[6];
	char gift[14];
	bool take;
	Member() {
		take = false;
	}
};

bool isPrime(int num) {
	int i;
	for (i = 2; i <= sqrt(num); i++)
		if (num % i == 0)
			return false;
	return true;
}

int main() {
	int N;
	cin >> N;
	Member member;
	vector<Member> members;
	char one[] = "Mystery Award";
	char two[] = "Minion";
	char three[] = "Chocolate";
	char fuck[] = "Are you kidding?";
	char take[] = "Checked";
	int* map = (int*)calloc(10000, sizeof(int));
	int i, j, k;
	for (i = 1; i <= N; i++) {
		cin >> j;
		sprintf(member.id, "%04d", j);
		if (i == 1)
			strcpy(member.gift, one);
		else if (isPrime(i))
			strcpy(member.gift, two);
		else
			strcpy(member.gift, three);
		members.push_back(member);
		map[j] = i;
	}
	cin >> k;
	for (i = 0; i < k; i++) {
		cin >> j;
		if (map[j]) {
			if (!members[map[j] - 1].take) {
				cout << members[map[j] - 1].id << ": " << members[map[j] - 1].gift << endl;
				members[map[j] - 1].take = true;
			}
			else
				cout << members[map[j] - 1].id << ": " << take << endl;
		}
		else {
			printf("%04d", j);
			cout << ": " << fuck << endl;
		}
	}
	free(map);
	return 0;
}
