#include <iostream>
using namespace std;
int main()
{
   double x, p, y;
	cin >> x >> p >> y;
	int k = 0;
	while (x < y) {
		x = x + x * p / 100.0;
		x = (int)(x * 100) / 100.0;
		k++;
        cout << x << endl;
	}
	cout << k;

    return 0;
}
