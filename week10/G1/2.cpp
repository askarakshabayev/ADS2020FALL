#include <iostream>
#include <vector>
#define ll long long

using namespace std;

ll p_pow[100];
ll p;

vector<ll> hash_(string s) {
    p = 31;
    p_pow[0] = 1;
    for (int i = 1; i < s.size(); i++)
        p_pow[i] = p_pow[i - 1] * p;

    vector<ll> result(s.size());
    result[0] = s[0];
    for (int i = 1; i < s.size(); i++) {
        result[i] = result[i - 1] + s[i] * p_pow[i];
    }
    return result;
}

int main() {
    string s;
    int i1, i2, len;
    cin >> s >> i1 >> i2 >> len;

    vector<ll> h = hash_(s);
    // calculate h1
    ll h1 = h[i1 + len - 1];
    if (i1 > 0)
        h1 -= h[i1 - 1];
    // calculate h2
    ll h2 = h[i2 + len - 1];
    if (i2 > 0)
        h2 -= h[i2 - 1];

    if ((i2 > i1 && h2 == h1 * p_pow[i2 - i1]) || (i1 >= i2 && h1 == h2 * p_pow[i1 - i2])) 
        cout << "YES";
    else 
        cout << "NO";

    return 0;
}