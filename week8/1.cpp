#include <iostream>

using namespace std;

int main() {
    string s;
    int p = 31;
    cin >> s;
    long long hash = 0;
    long long p_pow = 1;
    for (int i = 0; i < s.size(); i++) {
        hash += (s[i] - 'a' + 1) * p_pow;
        p_pow *= p; 
    }
    return 0;
}