#include <iostream>
#include <vector>

using namespace std;
vector<int> g[100];
// g[i] -> i 
int n, m, x, y;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        for (int j = 0; j < g[i].size(); j++)
            cout << g[i][j] << " ";
        cout << endl;
    }
    return 0;
}