#include <algorithm>
#include <iostream>
class Station {
public:
    double price, distance;
} gas[502];

bool cmp(Station a, Station b) {
    if (a.distance != b.distance)
        return a.distance < b.distance;
    return a.price < b.price;
}

int main() {
    int    N, i, step, index;
    double cost = 0, distance = 0, Cmax, Davg, D, Dmax, residue = 0;
    bool   flag;
    scanf("%lf%lf%lf%d", &Cmax, &D, &Davg, &N);
    Dmax = Davg * Cmax;
    for (i = 0; i < N; i++)
        scanf("%lf%lf", &gas[i].price, &gas[i].distance);
    gas[N].price = 0, gas[N].distance = D;
    std::sort(gas, gas + N, cmp);
    if (gas[0].distance != 0) {
        printf("The maximum travel distance = %.2f", 0);
        return 0;
    }
    for (i = 0; i < N; i = index) {
        index = i + 1;
        for (step = i + 1, flag = false; step <= N; step++) {
            if (gas[step].distance - distance > Dmax)
                break;
            flag = true;
            if (gas[index].price > gas[step].price)
                index = step;
            if (gas[index].price < gas[i].price)
                break;
        }
        if (!flag) {
            distance += Dmax;
            printf("The maximum travel distance = %.2f", distance);
            return 0;
        }
        distance = gas[index].distance;
        if (gas[index].price < gas[i].price) {
            cost += (distance - gas[i].distance - residue * Davg) / Davg * gas[i].price;
            residue = 0;
        } else {
            cost += (Cmax - residue) * gas[i].price;
            residue = (Dmax + gas[i].distance - distance) / Davg;
        }
    }
    printf("%.2f", cost);
    return 0;
}
