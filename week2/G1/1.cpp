#include <iostream>
#include <queue>

using namespace std;

int used[100];

int find_dist(int a, int b) {
    queue<pair<int, int> > q;
    q.push(make_pair(a, 0));
    used[a] = 1;

    while (!q.empty()) {
        int p = q.front().first;
        int d = q.front().second;

        if (p == b)
            return d;

        // p + 1
        if (used[p + 1] == 0) {
            q.push(make_pair(p + 1, d + 1));
            used[p + 1] = 1;
        }

        // p * 2
        if (used[p * 2] == 0) {
            q.push(make_pair(p * 2, d + 1));
            used[p * 2] = 1;
        }

        // p - 1
        if (p - 1 >= 0 && used[p - 1] == 0) {
            q.push(make_pair(p - 1, d + 1));
            used[p - 1] = 1;
        }

        // p / 2
        if (used[p / 2] == 0) {
            q.push(make_pair(p / 2, d + 1));
            used[p / 2] = 1;
        }

        q.pop(); 
    }
    return 0;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << find_dist(a, b);
    return 0;
}