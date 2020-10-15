#include <iostream>
#include <queue>

using namespace std;


int main() {
    deque<int> q;
    bool ok = true;

    int n, x, t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 1) {
            cin >> t;
            if (ok)
                q.push_back(t);
            else
                q.push_front(t);
        } else {
            if (ok)
                ok = false;
            else
                ok = true;
        }
    }

    if (ok) {
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop_front();
        }
    } else {
        while (!q.empty()) {
            cout << q.back() << " ";
            q.pop_back();
        }
    }

    return 0;
}