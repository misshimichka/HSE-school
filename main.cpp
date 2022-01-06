#include <iostream>
#include <vector>

using namespace std;


// n^3 -> n^2
bool isPal(string &s, int i, int j) {
    if (i >= j)
        return 1;
    auto f = (s[i] == s[j] && isPal(s, i+1, j-1));
    return f;
}

// 2^n * n --> n * n
int f(string &s, int i) {
    int n = s.size();
    if (i == n)
        return 0;
    int m = n;
    for (int j = i; i < n; j++) {
        if (isPal(s, i, j)) {
            m = min(m, 1 + f(s, j + 1));
        }
    }
    return m;
}
int main() {
    string s = "abaaaxyzyxxyyx";
    cout << f(s, 1);

    return 0;
}