#include <algorithm>
#include <iostream>
#include <string>
int main() {
    int D, N;
    scanf("%d%d", &D, &N);
    std::string num = std::to_string(D);
    for (int i = 1; i < N; i++) {
        int j = 0, k;
        std::string temp;
        while (j < num.size()) {
            for (k = j; k < num.size(); k++)
                if (num[k] != num[j])
                    break;
            temp.push_back(num[j]);
            temp += std::to_string(k - j);
            j = k;
        }
        num = temp;
    }
    std::cout << num;
    return 0;
}
