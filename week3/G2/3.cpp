#include <iostream>
#include <vector>

using namespace std;

int lower_bound_bin_search(vector<int> &a, int k) {

    // a[x] >= k
    int l = 0; 
    int r = a.size() - 1;
    int res = -1;
    while (l < r)  {
        int m = (l + r) / 2;
        if (a[m] >= k) { 
            res = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    if (a[r] > k)
        res = r;
    return res;
}

int upper_bound_bin_search(vector<int> &a, int k) {

    // a[x] > k
    int l = 0; 
    int r = a.size() - 1;
    int res = -1;
    while (l < r)  {
        int m = (l + r) / 2;
        if (a[m] > k) { 
            res = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    if (a[r] > k)
        res = r;
    return res;
}


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0;i < n; i++)
        cin >> a[i];
    int index = upper_bound_bin_search(a, k);
    cout << index;
    return 0;
}