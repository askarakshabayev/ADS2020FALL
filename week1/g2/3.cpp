#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(15);
    st.push(1);

    cout << st.top() << endl; // 10, 20
    st.pop();
    st.pop();
    cout << st.top() << endl;
    cout << st.size() << endl;
    cout << st.empty();

    return 0;
}
