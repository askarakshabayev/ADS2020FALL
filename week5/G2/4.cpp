// a * b N
// f(x) = 1, x => x + 1
// f(x) = 0
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13
// 0 0 0 0 0 0 0 1 1 1 1  1  1  1
//             l r               
// f(l) = 0
// f(r) = 1

#include <iostream>

using namespace std;

int x[2 * 100010], y[2 * 100010];
int xx, yy;
int n, k;

int f(int w) {
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (w >= x[i] && w >= y[i])
            t++;
    }
    if (t >= k)
        return 1;
    return 0;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> xx >> yy;
        cin >> x[i] >> y[i];
    }
    int l = 0;
    int r = 1e9;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (f(m) == 0) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << r;
    return 0;
}

