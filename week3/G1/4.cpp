#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x;
    cin >> x;
    double l = 1;
    double r = x;
    double eps = 0.00000000001;
    while (abs(r - l) > eps) {
        double m = (r + l) / 2.0;
        if (m * m * m < x)
            l = m;
        else 
            r = m;
    }
    printf("%.10lf", l);
    return 0;
}