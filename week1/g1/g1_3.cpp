#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> st;
    st.push(10);
    st.push(14);
    st.push(12);
    st.push(4);

    // cout << st.top();
    st.pop();
    st.pop();
    cout << st.top() << endl;
    cout << st.size() << endl;
    cout << st.empty();

    return 0;
}