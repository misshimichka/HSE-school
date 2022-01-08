#include <iostream>
#include <unordered_set>
#include <vector>
#include <bitset>
using namespace std;

// отрезки
#define all(a) (a).begin(), (a).end()

int main() {
    int n;
    cin >> n;
    vector <pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].second >> a[i].first;
    }
    sort(all(a));
    int endR = INT_MIN, count = 0;
    for(auto [R, L] : a) {
        if (L > endR) {
            count++;
            endR = R;
        }
    }
    cout << count << endl;
}