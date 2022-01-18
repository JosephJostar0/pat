#include<iostream>
#include<algorithm>
#include<stack>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main() {
    //后来发现不是所有的结点都是连在链表中的结点。。。真的太坑了吧。。。
    int first = 0, num;
    unsigned int k;
    cin >> first >> num >> k;
    stack<int> myStack;
    int* data = (int*)malloc(100000 * sizeof(int));
    int* next = (int*)malloc(100000 * sizeof(int));
    int address;
    int i;
    bool flag = false;//判断是否需要补点

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
            if (myStack.size() == k) {//此时有效结点总数%k=0且正好走到最后，那么逆序打印后结束
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
            else {//此时有效结点数%k!=0且走到了最后,那么顺序打印后结束
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
        else {//此时正常执行一轮逆序输出
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
