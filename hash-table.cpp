#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// хеш-таблица

const int n = 1e6;
const int N = 2 * n;

vector <int> key(N, -1);
vector <int> value(N);

int ind(int i) {
    int index = i % N;
    while (key[index] != -1 && key[index] != i) {
        index = (index + 1) % N;
    }
    return index;
}

void put(int i, int x) {
    int index = ind(i);
    key[index] = i;
    value[index] = x;
}

int get(int i) {
    int index = int(i);
    return key[index] != i ? -1 : value[index];
}

int count(int i) {
    int index = ind(i);
    return key[index] == i;
}

int main() {
    int n, x, s;
    cin >> n;
    unordered_set<int> a;
    for (int i = 0; i < (int) n; i++) {
        cin >> x, a.insert(x);
    }
    cin >> s;
    auto solve = [&]() {
        for (int x : a)
            for (int y : a)
                if (a.count(s - x - y)) {
                    printf("%d %d %d \n", x, y, s - x - y);
                    return;
                }
    };
    solve();
}