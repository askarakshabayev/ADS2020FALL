#include <iostream>
#define ll long long
using namespace std;


bool f(ll a, ll b, ll n, ll x) {
    if ((x / a) * (x / b) >=n)
        return true;
    return false;
}

ll bin_search(ll a, ll b, ll n) {
    ll l = 0;
    ll r = 1e9;

    while (l + 1 < r) { // 
        ll x = (l + r) / 2;
        if (f(a, b, n, x))
            r = x;
        else
            l = x;
    }
    return r;
}


int main () {
    ll a, b, n;

    cin >> a >> b >> n;
    cout << bin_search(a, b, n);

    return 0;
}