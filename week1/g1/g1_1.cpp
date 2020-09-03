#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        // cout << a << " " << b << endl;
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    // if (a > 0)
    //     return a;
    // return b;
    return a + b;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << gcd(n, m);
    return 0;
}