#include <iostream>

using namespace std;

int gcd(int a, int b) {
    for (int i = min(a, b); i >= 1; i--) {
        if (a % i == 0 && b % i == 0)
            return i;
    }
    return 1;
}

int gcd1(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b)
            a = a % b;
        else
            b = b % a;        
    }

    // if (a > 0)
    //     return b;
    // return a;
    return a + b;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd1(a, b);
    return 0;
}