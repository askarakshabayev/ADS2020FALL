#include <iostream>

using namespace std;
int a[10000000];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                swap(a[i], a[j]);
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}