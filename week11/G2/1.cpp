#include <iostream>
#include <set>

using namespace std;

int main() {
    string s;
    set<string> a;

    cin >> s;

    for (int i = 0; i < s.size(); i++) { // i = 2, abab
        string w = "";
        for (int j = i; j < s.size(); j++) { // w = 'ab'
            w += s[j];
            a.insert(w);
        }
    }
    cout << a.size();
    return 0;
}