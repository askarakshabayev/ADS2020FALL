#include <iostream>
#include <vector>
#define ll long long

using namespace std;
ll p = 31;
ll p_pow[100];

void calc_pow() {
    p_pow[0] = 1;
    for (int i = 1; i < 100; i++)
        p_pow[i] = p_pow[i - 1] * p;
}

ll hash_(string s) {
    ll sum = 0;
    for (int i = 0; i < s.size(); i++)
        sum += s[i] * p_pow[i];
    return sum;
}

vector<ll> hash_prefix(string s) {
    vector<ll> h(s.size());
    h[0] = s[0];
    for (int i = 1; i < s.size(); i++)
        h[i] = h[i - 1] + s[i] * p_pow[i];
    return h;
}

int main() {
    calc_pow();
    string s, t;
    cin >> s >> t;
    ll hash_t = hash_(t);
    vector<ll> h = hash_prefix(s);
    int n = s.size();
    int m = t.size();

    for (int i = 0; i + m - 1 < n; i++) {
        int j = i + m - 1;
        ll hash_i_j = h[j];
        if (i)
            hash_i_j -= h[i - 1];
        if (hash_t * p_pow[i] == hash_i_j)
            cout << i << " ";        
    }

    return 0;
}