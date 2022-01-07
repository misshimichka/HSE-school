#include <iostream>
#include <unordered_set>
using namespace std;

// 3-SUM

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