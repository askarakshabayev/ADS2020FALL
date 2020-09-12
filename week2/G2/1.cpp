#include <iostream>
#include <queue>

using namespace std;

int main() {
    // queue<int> q;
    // q.push(10);
    // q.push(20);
    // q.push(30);
    // cout << q.front() << endl; 
    // q.pop();
    // cout << q.front() << endl;
    // cout << q.size() << endl;
    // cout << q.empty();

    deque<int> q;
    q.push_back(10); 
    q.push_back(20);
    q.push_front(30);
    q.push_front(40);

    cout << q.front() << endl;
    cout << q.back() << endl;
    return 0;
}