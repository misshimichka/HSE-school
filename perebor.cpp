#include <iostream>
#include <map>
#include <valarray>

using namespace std;

// полуперебор-полужадность
unordered_map<int, int> mem(1e5+1);

int f(int n) {
    if (n == 0)
        return 0;
    int m = n;
    for (int i = 1; i * i <= n; i++) {
        m = min(m, 1 + f(n - i * i));
    }
    return m;
}
unordered_map<int, int> memg(1e5+1);

int g(int n) {
    if (n == 0)
        return 0;
    if (memg.count(n))
        return mem[n];
    int m = n;
    int k = sqrt(n);
    for (int i = max(1, k - 30); i <= k; i++) {
        m = min(m, 1 + g(n - i * i));
    }
    return memg[n] = m;
}

int main() {
    for (int n = 1; n < 100; n++) {
        int F = f(n);
        int G = g(n);
        cout << n << " " << F << " " << G << endl;
    }
    return 0;
}
