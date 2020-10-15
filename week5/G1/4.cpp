#include <iostream>

using namespace std;

int x[2 * 100010], y[2 * 100010];
int n, k, a, b;

bool f(int h) {
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (x[i] <= h && y[i] <= h)
            cnt++;
    if (cnt >= k)
        return true;
    return false;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cin >> x[i] >> y[i];
    }

    int l = 0;
    int r = 1e9;
    int res = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (f(mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res;
    return 0;
}