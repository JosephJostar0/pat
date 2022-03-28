#include <iostream>
#include <string>
bool cmp(std::string a, std::string b) { // if a smaller than b return true
    if (std::stoi(a.substr(0, 2)) == std::stoi(b.substr(0, 2))) {
        if (std::stoi(a.substr(3, 2)) == std::stoi(b.substr(3, 2)))
            return std::stoi(a.substr(7, 2)) < std::stoi(b.substr(7, 2));
        return std::stoi(a.substr(3, 2)) < std::stoi(b.substr(3, 2));
    }
    return std::stoi(a.substr(0, 2)) < std::stoi(b.substr(0, 2));
}

int main() {
    std::string lock, unlock, id;
    std::string in, out;
    std::string early, last;
    int         M, i;
    std::cin >> M;
    std::cin >> id >> in >> out;
    lock = id, unlock = id, early = in, last = out;
    for (i = 1; i < M; i++) {
        std::cin >> id >> in >> out;
        if (cmp(in, early))
            unlock = id, early = in;
        if (cmp(last, out))
            lock = id, last = out;
    }
    std::cout << unlock << ' ' << lock;
    return 0;
}
