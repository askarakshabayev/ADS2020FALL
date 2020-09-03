#include <iostream>
#include <cmath>

using namespace std;

void find_primes(int n) {
    for (int x = 2; x <= n; x++) {
        bool is_prime = true;
        for (int y = 2; y * y <= x; y++) {
            if (x % y == 0)
                is_prime = false;
        }
        if (is_prime)
            cout << x << " ";
    }
}

int p[10000010];

void find_primes1(int n) {
    // for (int i = 2; i <= sqrt(n); i++)
    for (int i = 2; i * i <= n; i++) { 
        if (p[i] == 0) {
            int k = i;                 
            while (k + i <= n) {
                k += i;
                p[k] = 1;
            }
        }
    }

    for (int i = 2; i <= n; i++)
        if (p[i] == 0)
            cout << i << " ";

}

int main() {
    int n;
    cin >> n;
    find_primes1(n);
    return 0;
}