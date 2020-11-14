#include <iostream>
#define ll long long

using namespace std;

ll hash_(string s) {
    ll p = 31;
    ll p_pow = 1; // p ^ 0
    ll sum = 0;
    for (int i = 0; i < s.size(); i++) { // i = 0, 1
        sum += s[i] * p_pow;             // s[0] * 1 + s[1] * 31 + s[2] * 31^2
        p_pow *= p;
    }
    return sum;
}

int main() {
    string s1, s2;

    cin >> s1 >> s2;
    if (hash_(s1) == hash_(s2))
        cout << "YES";
    else 
        cout << "NO";
    return 0;
}