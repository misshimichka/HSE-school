#include <iostream>
#include <map>

using namespace std;

// считает из скольки квадратов состоит число
int f(int n) {
    if (n == 0)
        return 0;
    int m = n;
    for (int i = 1; i * i <= n; i++) {
        m = min(m, 1 + f(n - i * i));
    }
    return m;
}
int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;

    return 0;
}