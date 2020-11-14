#include <iostream>
#define ll long long

using namespace std;

ll hash_(string s) {
    ll p = 31;
    ll p_pow = 1;
    ll sum = 0;
    for (int i = 0; i < s.size(); i++) {
        sum += s[i] * p_pow;
        p_pow *= p;
    }
    return sum;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    if (hash_(s1) == hash_(s2)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    
    return 0;
}