#include <iostream>
#include <queue>

using namespace std;

int a[10][10];
pair<int, int> c[10][10];

queue<pair<int, int> > q;

int dx[8] = {2,  2, -2, -2,  1, 1, -1, -1};
int dy[8] = {1, -1,  1, -1, -2, 2, -2,  2};

bool check(int x, int y) {
    return (x >= 1 && x <= 8 && y >= 1 && y <= 8 && a[x][y] == 0);
}
int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    a[x1][y1] = 1;
    q.push(make_pair(x1, y1));
    c[x1][y1] = make_pair(x1, y1);

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        for (int i = 0; i < 8; i++) {
            if (check(x + dx[i], y + dy[i])) {
                q.push(make_pair(x + dx[i], y + dy[i]));
                a[x + dx[i]][y + dy[i]] = a[x][y] + 1;
                c[x + dx[i]][y + dy[i]] = make_pair(x, y);
            }
        }

        q.pop();
    }

    // for (int i = 1; i <= 8; i++) {
    //     for (int j = 1; j <= 8; j++) 
    //         cout << a[i][j] << " ";
    //     cout << endl;
    // }
    cout << a[x2][y2] - 1 << endl;

    vector<pair<int, int> > result;
    result.push_back(make_pair(x2, y2));
    int x = x2;
    int y = y2;
    while (c[x][y] != make_pair(x, y)) { // c[7][4] = (6, 6)
        int x_temp = c[x][y].first; // x = 7, y = 4
        int y_temp = c[x][y].second; 
        result.push_back(make_pair(x_temp, y_temp));
        x = x_temp;
        y = y_temp;
    }

    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i].first << " " << result[i].second << endl;
    return 0;
}