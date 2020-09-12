#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next, *prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LinkedList {
    public:
    Node *tail, *front;

    LinkedList() {
        tail = NULL;
        front = NULL;
    }

    void push_back(int data) {
        Node *node = new Node(data);
        if (tail == NULL) {
            tail = node;
            front = node;
        } else {
            node->next = tail;
            tail->prev = node;
            tail = node;
        }
    }

    void push_front(int data) {
        Node *node = new Node(data);
        if (front == NULL) {
            tail = node;
            front = node;
        } else {
            front->next = node;
            node->prev = front;
            front = node;
        }
    }

    void insert(Node *a, int data) {
        if (a == front)
            push_front(data);
        Node *c = new Node(data);

        Node *b = a->next;
        a->next = c;
        c->prev = a;
        c->next = b;
        b->prev = c;
    }

    void pop_front() {

    }
    void pop_back() {

    }

    void del(Node *node) {
        
    }
};

int main() {
    return 0;
}