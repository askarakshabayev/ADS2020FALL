// ....l1.......r1....l2......r2........
// ....l2.......r2....l1......r1.......
// ....l1....l2...r1.....r2.............
// ....l2.......l1....r2...r1...........

// 7 3
// 21 1 2 3 5 8 13
//  -1 0 1 2 3 4 5  6  7
// -oo 1 2 3 5 8 13 21 oo
//             l  r
// max: <= x, x = 9
// a[l] <= x
// a[r] > x
// l = 4
// r = 7
// m = (l + r) / 2
// a[m]
// res = 3
// l -> m + 1
// r > m - 1

// -oo 5 6 7 8 9 10 oo
// l   r         
// x = 4

#include <iostream>

using namespace std;
int a[100010];
int n, m;

// max: a[i] <= x
int f(int x) {
    // a[l] <= x
    // a[r] > x
    int l = -1;
    int r = n;
    while (l + 1 < r) { 
        int m = (l + r) / 2;
        if (a[m] <= x) {
            l = m; 
        } else {
            r = m;
        }
    }

    return l + 1;
}

int query(int l, int r) {
    return f(r) - f(l - 1);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int l1, r1, l2, r2;
    for (int i = 0; i < m; i++) {
        cin >> l1 >> r1 >> l2 >> r2;
        if (r1 < l2 || r2 < l1) {
            cout << query(l1, r1) + query(l2, r2) << endl;
        } else {
            int min_l = min(l1, l2);
            int max_r = max(r1, r2);
            cout << query(min_l, max_r) << endl;
        }
    }
    return 0;
}

