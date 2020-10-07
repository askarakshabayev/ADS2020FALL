#include <iostream>
#include <stack>

using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> st;

    int cur = 1;
    for (int i = 0; i < s.size(); i++) {
        if (!st.empty() && st.top() == s[i]) {
            st.pop();
            cur = 3 - cur;
        } else {
            st.push(s[i]);
        }
    }

    if (cur == 1)
        cout << "No";
    else
    {
        cout << "Yes";
    }
    
    return 0;
}