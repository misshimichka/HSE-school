#include <iostream>
#include <map>
#include <valarray>
#include <vector>

using namespace std;

// задача о рюкзаке со стоимостями
// min(n*S, 2^n)
map<pair<int, int>, bool> mem;

int f(int i, int w, int S, vector<int> &a, vector<int> &cost) {
    int n = a.size();
    if (w > S) return INT_MIN;
    if (i == n) return 0;
    if (mem.count({i, w}))
        return mem[{i, w}];
    return mem[{i, w}] =
                   max(f(i + 1, w, S, a), f(i + 1, w + a[i], S, a);
}

int main() {
    vector<int> a = {1, 2, 3};
    vector<int> cost = {9, 1, 2};
    cout << f(0, 0, 5, a, cost) << endl;
    return 0;
}