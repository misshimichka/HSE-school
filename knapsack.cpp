#include <iostream>
#include <map>
#include <valarray>
#include <vector>

using namespace std;

// задача о рюкзаке
map<pair<int, int>, bool> mem;

bool f(int i, int w, int S, vector <int> &a) {
    int n = a.size();
    if (i == n)
        return w == S;
    if mem.count({i, w})
        return mem[{i, w}];
    return mem[{i, w}] =
            f(i + 1, w, S, a) || f(i + 1, w + a[i], S, a);
}

int main() {
    int S = 4;
    vector<int> a = {1, 2, 3};
    cout << f(0, S, a) << endl;
    return 0;
}

