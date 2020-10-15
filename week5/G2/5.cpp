#include <iostream>

using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        int k = 0;
        for (int j = 2; j * j <= i; j++)
            if (i % j == 0)
                k++;
        if (k == 1) {
            // cout << i << " ";
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}