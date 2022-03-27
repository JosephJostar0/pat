#include <iostream>
#include <map>
std::map<int, double> result;
std::map<int, double> last;
/**
 * 其实可以优化到只用一个map或者只用一个double数组
 * 但我直接用两个map也挺好，至少写起来很快
 */

int main() {
    int    num, index, count = 0;
    int    i, k;
    double value, j;
    scanf("%d", &num);
    for (k = 0; k < num; k++) {
        scanf("%d%lf", &index, &value);
        result[index] = value;
    }
    scanf("%d", &num);
    std::map<int, double>::iterator it;
    for (k = 0; k < num; k++) {
        scanf("%d%lf", &index, &value);
        for (it = result.begin(); it != result.end(); it++) {
            i = (*it).first + index;
            j = (*it).second * value;
            last[i] += j;
        }
    }
    for (it = last.begin(); it != last.end(); it++)
        if ((*it).second != 0)
            count++;
    printf("%d", count);
    for (k = 2000; k >= 0; k--)
        if (last[k] != 0)
            printf(" %d %.1f", k, last[k]);
    return 0;
}
