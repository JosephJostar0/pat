#include <iostream>
using namespace std;
int main() {
    int map[128] = { 0 }, c;
    while ((c = cin.get()) != EOF)
        map[c]++;
    while (map['P'] || map['A'] || map['T'] || map['e'] || map['s'] || map['t']) {
        if (map['P']--)
            cout << 'P';
        if (map['A']--)
            cout << 'A';
        if (map['T']--)
            cout << 'T';
        if (map['e']--)
            cout << 'e';
        if (map['s']--)
            cout << 's';
        if (map['t']--)
            cout << 't';
    }
    return 0;
}