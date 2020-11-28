#include <iostream>
#include <vector>

using namespace std;
int n, m, x, y;
vector<int> g[100];
int used[100];
vector<int> result;

void dfs(int v) {
    // cout << v << endl;
    used[v] = 1;
    for (int i = 0; i < g[v].size(); i++)
        if (used[g[v][i]] == 0)
            dfs(g[v][i]);

    result.push_back(v);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        // g[y].push_back(x);
    }

    for(int i = 0; i < n; i++)
        if (used[i] == 0)
            dfs(i);

    for (int i = 0; i < n; i++)
        cout << result[i] + 1 << " ";

    return 0;    
}