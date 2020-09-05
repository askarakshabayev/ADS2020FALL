#include <iostream>

using namespace std;

void primes(int n) {
    for (int i = 2; i <= n; i++) {
        bool is_prime = true;
        for (int j = 2; j * j <= i; j++) 
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        if (is_prime) 
            cout << i << " ";
    }
}

int p[100000002];
void primes1(int n) {
    // n = 25
    for (int i = 2; i * i <= n; i++) { // i = 2, 3, 4, 5
        if (p[i] == 0) {
            int k = i;                     // k = 10, 15, 20, 25
            while (k + i <= n) {           // 
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
    primes1(n);
    return 0;
}