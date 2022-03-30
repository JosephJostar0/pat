#include <iostream>
#include <string>
int main() {
    std::string Day[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    std::string str1, str2, str3, str4;
    std::getline(std::cin, str1);
    std::getline(std::cin, str2);
    std::getline(std::cin, str3);
    std::getline(std::cin, str4);
    int i;
    for (i = 0; i < str1.size() && i < str2.size(); i++)
        if (str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G')
            break;
    std::cout << Day[(str1[i] - 'A')] << ' ';
    for (i++; i < str1.size() && i < str2.size(); i++)
        if (str1[i] == str2[i]) {
            if (str1[i] >= 'A' && str1[i] <= 'N') {
                std::cout << (str1[i] - 'A' + 10) << ':';
                break;
            } else if (str1[i] >= '0' && str1[i] <= '9') {
                printf("%02d:", (int)(str1[i] - '0'));
                break;
            }
        }
    for (i = 0; i < str3.size() && i < str4.size(); i++)
        if (str3[i] == str4[i])
            if ((str3[i] >= 'A' && str3[i] <= 'Z') ||
                (str3[i] >= 'a' && str3[i] <= 'z'))
                break;
    printf("%02d", i);
    return 0;
}
