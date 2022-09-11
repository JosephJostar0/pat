#include <iostream>
using namespace std;
int N, T, K;

int check(string line) {
    int  grade = 0, i, len = line.size();
    char letter = line[0];
    int  t = 1, tt = 1;
    if (line[0] == 'f')
        grade -= 2;
    if (line[len - 1] == 'a')
        grade -= 1;
    for (i = 1; i < len; i++) {
        if (line[i] == letter)
            t++;
        else {
            if (t > 5)
                grade += 3;
            t = 1;
        }
        if ((int)line[i] == (int)(letter + 1))
            tt++;
        else {
            if (tt > 3)
                grade += 5;
            tt = 1;
        }
        if (letter == 'a')
            if (line[i] == 'e' || line[i] == 'h')
                grade -= 4;
        letter = line[i];
    }
    if (t > 5)
        grade += 3;
    if (tt > 3)
        grade += 5;
    return grade;
}

int main() {
    int i, j, k;
    scanf("%d %d %d", &N, &T, &K);
    string line;
    for (i = 0; i < K; i++) {
        cin >> line;
        j = check(line);
        printf("%d", j);
        if (j > T)
            printf("!!!");
        printf("\n");
    }
    return 0;
}