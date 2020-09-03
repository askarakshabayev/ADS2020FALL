#include <iostream>

using namespace std;

bool is_ok(string s) {
    int k = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            k++;
        else
            k--;
        if (k < 0)
            return false;
    }
    if (k == 0)
        return true;
    return false;
}

int main() {
    string s;
    cin >> s;
    if (is_ok(s)) 
        cout << "YES";
    else
        cout << "NO";
    
    return 0;
}