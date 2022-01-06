#include <iostream>
#include <map>
#include <valarray>
#include <vector>

using namespace std;

// домино
// 2^n
// найти количество доминошек: 2 в степени (h*w/2)
// динамика по профилю

int go(int x, int y, int w, int h, vector<vector<int>> &a) {
    if (y == h) x++, y = 0;
    if (x == w)
        return 1;
    if (a[y][x])
        return go(x, y + 1, w, h, a);
    int ans = 0;
    if (x + 1 < w && a[y][x + 1] == 0){
        a[y][x] = a[y][x + 1] = 1;
        ans += go(x, y + 1, w, h, a);
        a[y][x] = a[y][x + 1] = 0;
    }
    if (y + 1 < h && a[y + 1][x] == 0){
        a[y][x] = a[y + 1][x] = 1;
        ans += go(x, y + 1, w, h, a);
        a[y][x] = a[y + 1][x] = 0;
    }
    return ans;
}

int main() {
    int w = 5, h = 5;
    vector<vector<int>> a(h, vector<int>(w, 0));
    cout << go(0, 0, w, h, a) << endl;
    return 0;
}

