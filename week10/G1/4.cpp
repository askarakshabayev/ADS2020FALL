#include <iostream>
#include <vector>

using namespace std;

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> p(n, 0);
    for (int i = 0; i < n; i++) { // 0 .. i
        for (int k = 1; k <= i; k++) {
            if (s.substr(0, k) == s.substr(i - k + 1, k))
                p[i] = k;
        }
    }
    return p;
}

int main() {
    string s;
    cin >> s;
    vector<int> p = prefix_function(s);
    for (int i = 0; i < s.size(); i++)
        cout << p[i] << " ";
    return 0;
}