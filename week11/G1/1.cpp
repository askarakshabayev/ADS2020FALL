#include <iostream>
#include <set>

using namespace std;
set<string> a;

int main() {
    string s;
    cin >> s;
    // abab
    for (int i = 0; i < s.size(); i++) { 
        string w = "";
        for (int j = i; j < s.size(); j++) { 
            w += s[j]; 
            a.insert(w);
        }
    }
    cout << a.size();
    return 0;    
}