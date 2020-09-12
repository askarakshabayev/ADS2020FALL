#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int data) {
        this->data = data;
    }
};

class LinkedList {
    public:
    Node *tail, *front;

    LinkedList() {
        tail = NULL;
        front = NULL;        
    }

    void push_front(int data) {
        Node *node = new Node(data);

        if (this->front == NULL) {
            front = node;
            tail = node;
        } else {
            front->prev = node;
            node->next = front;
            front = node;
        }
    }

    void push_back(int data) {
        Node *node = new Node(data);

        if (this->tail == NULL) {
            tail = node;
            front = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void insert(Node *node, int data) {

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