#include <iostream>
#define ll long long

using namespace std;

ll a, b, n;
bool f(ll x) {
    return ((x / a) * (x / b)) >= n;
}

int main() {
    cin >> a >> b >> n;

    ll l = 0;
    ll r = 1e9;
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        if (f(m))
            r = m;
        else 
            l = m;
    }
    cout << r;
    return 0;
}