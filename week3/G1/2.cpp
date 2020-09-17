#include <iostream>
#include <vector>

using namespace std;

int find_ind(vector<int> &a, int k) {
    for (int i = 0; i < a.size(); i++)
        if (a[i] == k)
            return i;
    return -1;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    int index = find_ind(a, k);
    cout << index;
    return 0;
}