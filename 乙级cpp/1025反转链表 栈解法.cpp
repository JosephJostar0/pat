#include<iostream>
#include<algorithm>
#include<stack>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main() {
    //�������ֲ������еĽ�㶼�����������еĽ�㡣�������̫���˰ɡ�����
    int first = 0, num;
    unsigned int k;
    cin >> first >> num >> k;
    stack<int> myStack;
    int* data = (int*)malloc(100000 * sizeof(int));
    int* next = (int*)malloc(100000 * sizeof(int));
    int address;
    int i;
    bool flag = false;//�ж��Ƿ���Ҫ����

    for (i = 0; i < num; i++) {
        cin >> address;
        cin >> data[address] >> next[address];
    }
    int current = first, temp = first;

    while (current !=-1) {
        while (current != -1 && myStack.size() < k) {
            myStack.push(current);
            current = next[current];
        }
        if (current == -1) {
            if (myStack.size() == k) {//��ʱ��Ч�������%k=0�������ߵ������ô�����ӡ�����
                while (myStack.size() > 1) {
                    temp = myStack.top();
                    myStack.pop();
                    if (flag)
                        printf("%05d\n", temp);
                    printf("%05d %d ", temp, data[temp]);
                    flag = true;
                }
                temp = myStack.top();
                if (flag)
                    printf("%05d\n", temp);
                printf("%05d %d -1\n", temp, data[temp]);
                break;
            }
            else {//��ʱ��Ч�����%k!=0���ߵ������,��ô˳���ӡ�����
                while (myStack.size() > 1) {
                    myStack.pop();
                }
                temp = myStack.top();
                if (flag)
                    printf("%05d\n", temp);
                while (next[temp] != -1) {
                    printf("%05d %d %05d\n", temp, data[temp], next[temp]);
                    temp = next[temp];
                }
                printf("%05d %d -1\n", temp, data[temp]);
                break;
            }
        }
        else {//��ʱ����ִ��һ���������
            while (!myStack.empty()) {
                temp = myStack.top();
                myStack.pop();
                if (flag)
                    printf("%05d\n", temp);
                printf("%05d %d ", temp, data[temp]);
                flag = true;
            }
        }
    }

    free(data);
    free(next);
    return 0;
}
