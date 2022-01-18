#include<iostream>
using namespace std;

class student {
public:
	int Id;		//׼��֤�� 
	int virtue;	//�� 
	int ability;//��
	int rank;	//�ڼ���
	void setIVA(int id, int v, int a) {
		Id = id;
		virtue = v;
		ability = a;
	}
	int getVandA() {
		return virtue + ability;
	}
	void print() {
		printf("%d %d %d\n", Id, virtue, ability);
	}
	void setRank(int r) {
		rank = r;
	}
};

bool cmp(student stu1, student stu2) {//trueΪstu1��������stu2 
	if (stu1.rank == stu2.rank) {
		if (stu1.getVandA() == stu2.getVandA()) {
			if (stu1.virtue == stu2.virtue)
				return stu1.Id < stu2.Id;//׼��֤��С����ǰ 
			else
				return stu1.virtue > stu2.virtue;
		}
		else
			return stu1.getVandA() > stu2.getVandA();
	}
	else
		return stu1.rank < stu2.rank;
}

void giveRank(int L, int H, student& stu, int& num) {
	num++;
	if (stu.virtue >= H && stu.ability >= H) {
		stu.setRank(1);
	}
	else if (stu.virtue >= H) {
		stu.setRank(2);
	}
	else if (stu.virtue >= stu.ability) {
		stu.setRank(3);
	}
	else {
		stu.setRank(4);
	}
}

void heapDo(student heap[], int i, int num) {
	int dad = i, son = i * 2;
	student ex;
	while (son <= num) {
		if (son + 1 <= num && !cmp(heap[son], heap[son + 1]))
			son++;
		if (cmp(heap[dad], heap[son]))
			return;
		ex = heap[son];
		heap[son] = heap[dad];
		heap[dad] = ex;
		dad = son;
		son = dad * 2;
	}
}

void heapIn(student heap[], int num, student stu) {//���ô�С�� 
	int i;
	heap[num] = stu;
	for (i = num / 2; i > 0; i /= 2)
		heapDo(heap, i, num);
}

void heapOut(student heap[], int& num) {
	heap[0] = heap[1];
	heap[1] = heap[num--];
	heapDo(heap, 1, num);
}

int main() {
	//��һ�ࣺ�²ŷֶ�������H
	//�ڶ��ࣺ�²�����H���ŵ���H
	//�����ࣺ�²ž�����H���´��ڲ�
	//�����ࣺ�²ž�������L�ķ�ǰ���� 
	int N, L, H;
	cin >> N >> L >> H;
	int i, j, k, n;
	int num = 0;
	student heap[100001];
	student stu;
	for (n = 0; n < N; n++) {
		cin >> i >> j >> k;
		if (j < L || k < L)
			continue;
		stu.setIVA(i, j, k);
		giveRank(L, H, stu, num);
		heapIn(heap, num, stu);
	}

	cout << num << endl;
	while (num >= 1) {
		heapOut(heap, num);
		heap[0].print();
	}
	return 0;
}
