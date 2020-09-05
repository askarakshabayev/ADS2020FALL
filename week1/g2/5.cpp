#include <iostream>
#include <stack>

using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Stack {
    public:
    Node *top;
    int sz;

    Stack() {
        top = NULL;
        sz = 0;
    }

    void push(int data) {
        Node *node = new Node(data);
        node->next = top;
        top = node;
        sz++;
    }

    void pop() {
        if (top != NULL) {
            top = top->next;
            sz--;
        }
    }

    int size() {
        return this->sz;
    }

    bool empty() {
        // if (sz == 0)
        //     return true;
        // return false;
        return (sz == 0);
    }

};

int main() {
    Stack *st = new Stack();
    st->push(20);
    st->push(30);
    st->push(40);
    cout << st->top->data << endl;
    st->pop();
    cout << st->top->data << endl;
    cout << st->size() << endl;
    cout << st->empty() << endl;
    st->pop();
    st->pop();
    cout << st->empty();
    return 0;
}