#include <iostream>
#include <vector>

using namespace std;
int n, m, x, y;
vector<int> g[100];
int used[100];

void dfs(int v) {
    used[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        int y = g[v][i];
        if (used[y] == 0)
            dfs(y); 
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
            dfs(i);
            cnt++;
        }
    return 0;
}