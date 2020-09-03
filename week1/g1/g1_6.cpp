#include <iostream>
#include <stack>

using namespace std;

bool is_ok(string s) {
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            st.push(s[i]);
        else {
            if (st.empty())
                return false;
            char ch = st.top();
            if (ch == '(' && s[i] != ')')
                return false;
            if (ch == '[' && s[i] != ']')
                return false;
            if (ch == '{' && s[i] != '}')
                return false;
            st.pop();
        } 
    }

    // if (st.empty())
    //     return true;
    // return false;
    return (st.empty() == true);
}

int main() {
    string s;
    cin >> s;
    if (is_ok(s))
        cout << "YES";
    else
    {
        cout << "NO";
    }
    
    return 0;
}