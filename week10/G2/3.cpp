#include <iostream>
#include<vector>
#define ll long long

using namespace std;

ll p_pow[1000];

void init_p_pow(int n) {
    ll p = 31;
    p_pow[0] = 1;
    for (int i = 1; i <= n; i++)
        p_pow[i] = p_pow[i - 1] * p;
}

vector<ll> hash_(string s) {
    vector<ll> result(s.size());
    result[0] = s[0];
    for (int i = 1; i < s.size(); i++) 
        result[i] = result[i - 1] + s[i] * p_pow[i];
    return result;
}

ll hash_s(string s) {
    ll sum = 0;
    for (int i = 0; i < s.size(); i++)
        sum += s[i] * p_pow[i];
    return sum;
}

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    init_p_pow(s.size());
    vector<ll> h_p = hash_(s);
    ll h_t = hash_s(t);

    for (int i = 0; i + m - 1 < n; i++) {
        int j = i + m - 1;
        ll h = h_p[j];
        // i = 0 - false, > 0 => true
        if (i > 0) 
            h -= h_p[i - 1];

        if (h_t * p_pow[i] == h)
            cout << i << " ";
    }

    return 0;
}