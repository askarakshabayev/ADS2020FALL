// ok = true 
//      false

// ok = false
// 1 5 4 2 3 1
// 

#include <iostream>
#include <queue>

using namespace std;

int main() {
    deque<int> q;
    int n, x, t;
    bool ok = true;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 1) {
            cin >> t;
            if (ok)
                q.push_back(t);
            else
                q.push_front(t);            
        } else
            ok = !ok;
    }

    while (!q.empty()) {
        if (ok) {
            cout << q.front() << " ";
            q.pop_front();
        } else {
            cout << q.back() << " ";
            q.pop_back();
        }
    } 
    return 0;
}