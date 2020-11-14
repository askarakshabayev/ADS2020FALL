#include <iostream>
#include <vector>

using namespace std;

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> p(n, 0);
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[j] != s[i])
            j = p[j - 1];
        if (s[j] == s[i])
            j++;
        p[i] = j;
    }
    return p;
}

int main() {
    string s, t;
    cin >> s >> t;
    s = t + "#" + s;
    vector<int> p = prefix_function(s);
    for (int i = 0; i < s.size(); i++)
        if (p[i] == t.size())
            cout << i - 2 * t.size() << " ";
    return 0;
}