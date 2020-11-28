#include <iostream>
#include <vector>

using namespace std;
vector<int> g[100];
int used[100];
int n, m;

void dfs(int v) {
    used[v] = 1;
    for (int i = 0; i < g[v].size(); i++)
        if (used[g[v][i]] == 0)
            dfs(g[v][i]);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (used[i] == 0) {
            dfs(i);
            cnt++;
        }
    cout << cnt;
    return 0;
}