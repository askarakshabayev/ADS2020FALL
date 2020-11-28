#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector<int> g[100];
int used[100]; // u[i] = 0
int d[100];
int n, m, x, y;

void bfs(int v) {
    queue<int> q;
    used[v] = 1;
    d[v] = 0;
    q.push(v);
    while (!q.empty()) {
        int x = q.front();
        for (int i = 0; i < g[x].size(); i++) {
            int y = g[x][i]; // x - y
            if (used[y] == 0) {
                q.push(y);
                used[y] = 1;
                d[y] = d[x] + 1;
            }
        }
        q.pop();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (used[i] == 0) {
            bfs(i);
            cnt++;
        }
    

    // for (int i = 0; i < n; i++)
    //     cout << i + 1 << " --- " << d[i] << " " << endl;
    cout << cnt;
    return 0;
}
