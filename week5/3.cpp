#include <iostream>

using namespace std;

int n, l1, r1, l2, r2, k;
int a[100010];

int number_of_less(int limit) {
    int l = 0;
    int r = n - 1;
    int res = -1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] <= limit) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    if (res == -1)
        return 0;
    return res + 1;
}

int query(int l, int r) {
    return number_of_less(r) - number_of_less(l - 1);
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    for (int i = 0; i < k; i++) {
        cin >> l1 >> r1 >> l2 >> r2;
        if (l2 > r1 || l1 > r2)
            cout << query(l1, r1) + query(l2, r2) << endl;
        else {
            int min_l = min(l1, l2);
            int max_r = max(r1, r2);
            cout << query(min_l, max_r) << endl;
        }
    }

    return 0;
}