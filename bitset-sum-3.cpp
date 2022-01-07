#include <iostream>
#include <unordered_set>
#include <vector>
#include <bitset>
using namespace std;

// bitset
const int N = 1e5 + 1;
bitset<N> a, a2, a3;

int main() {
    // 0 <= x < s <= 10 ^ 5
    int n, s;
    cin >> n;
    vector <int> b(n);
    for (int i = 0; i < (int) n; i++) {
        cin >> b[i], a[b[i]] = 1;
    }

    // Магия

    // x = 2
    // a = 01010111100001
    // a = 00010101111000
    for (int x : b)
        a2 |= a << x; // N / 64

    // a2     = 1010101111
    // a << x = 1110100000
    // or     = 1110101111

    // a2[i] = 1 | i = x + y
    for (int x : b)
        a3 |= a2 << x;

    cin >> s;
    auto solve = [&]() {
        if (a3[s] == 1)
            for (int x : b)
                if (a2[s - x])
                    for (int y : b)
                        if (a[s - x - y]) {
                            printf("%d %d %d \n", x, y, s - x - y);
                            return;
                        }
    };
    solve();
}

// b - исходный массив
// а - числа, которые можем получить сложением одной переменной (1 - можем получить, 0 - не можем)
// а2 - числа, полученные сложением двух чисел
// а3 - числа, полученные сложением трех переменных