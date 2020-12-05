#include <iostream>
#define MAX_INT 1e7

using namespace std;
int a[100][100];
int d[100][100];
int c[100][100];

void r(int i, int j) {
    if (c[i][j] == -1) {
        cout << i + 1 << " " << j + 1 << endl;
        return;
    }
    r(i, c[i][j]);
    r(c[i][j], j);
}

int main() {
    int n, m, x, y, l;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> l;
        x--; y--;
        a[x][y] = l;
        a[y][x] = l;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] > 0)
                d[i][j] = a[i][j];
            else
                d[i][j] = MAX_INT;
            c[i][j] = -1;
        }
        d[i][i] = 0;
    }
            
    for (int k = 0; k < n; k++) 
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    c[i][j] = k;
                }

    cin >> x >> y;
    x--;y--;
    cout << d[x][y] << endl;
    r(x, y);
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++)
    //        cout << d[i][j] << " ";
    //     cout << endl;
    //  }
                    
    return 0;
}

// class e {
//     int x, y, l;
// };

// e g[100];

// for (int i = 0; i < n; i++) {
//     for (int j = 0; j < m; j++) {
//         x = e[j].x;
//         y = e[j].y;
//         l = e[j].l
//         if (d[y] > d[x] + l)
//             d[y] = d[x] + l;
//     }
// }