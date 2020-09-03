#include <iostream>

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
        Node *new_node = new Node(data);
        new_node->next = top;
        top = new_node;
        sz++;
    }

    void pop() {
        if (top != NULL) {
            top = top->next;
            sz--;
        }
    }

    bool empty() {
        // if (top == NULL) 
        //     return true;
        // return false;
        return (top == NULL);
    }

    int size() {
        return sz;
    } 
};

int main() {
    // Node *node1 = new Node(10);
    // Node *node2 = new Node(20);
    // Node *node3 = new Node(30);
    // node1->next = node2;
    // node2->next = node3;

    // cout << node1 << endl;
    // cout << node1->data << endl;
    // cout << node2 << " " << node1->next << endl;
    // cout << node1->next->next->data;

    Stack *st = new Stack();
    st->push(10);
    st->push(20);
    st->push(30);
    st->push(40);
    cout << st->top->data << endl;
    cout << st->size() << endl;
    cout << st->empty() << endl;
    st->pop();
    st->pop();
    cout << st->top->data;

    return 0;
}