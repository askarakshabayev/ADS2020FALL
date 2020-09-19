#include <iostream>
#include <vector>

using namespace std;

int find_index(vector<int> &a, int p) {
    for (int i = 0; i < a.size(); i++)
        if (a[i] == p)
            return i;
    return -1;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int index = find_index(a, k);
    cout << index;
    return 0;
}