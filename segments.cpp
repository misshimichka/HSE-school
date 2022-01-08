#include <iostream>
#include <unordered_set>
#include <vector>
#include <bitset>
using namespace std;

// отрезки (с использованием struct)
#define all(a) (a).begin(), (a).end()

int main() {
    int n;
    cin >> n;

    struct Segment {
        int L, R;
        bool operator < (Segment s) const {
            return R < s.R;
        }
    };
    vector <Segment> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].L >> a[i].R;
    }
    sort(all(a));
    int endR = INT_MIN, count = 0;
    for(auto s : a) {
        if (s.L > endR) {
            count++;
            endR = s.R;
        }
    }
    cout << count << endl;
}