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
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }

    void push_front(int data) {
        Node *node = new Node(data);
        if (front == NULL) {
            tail = node;
            front = node;
        } else {
            front->prev = node;
            node->next = front;
            front = node;
        }
    }

    void pop_back() {
        if (tail != NULL) {
            tail = tail->prev;
            if (tail != NULL)
                tail->next = NULL;
            else 
                front = NULL;
        }
    }

    void pop_front() {
        if (front != NULL) {
            front = front->next;
            if (front != NULL)
                front->prev = NULL;
            else
                tail = NULL;
        }
    }

    void del_node(Node *node) {
        if (node == tail)
            pop_back();
        else if (node == front) 
            pop_front();
        else {
            Node *a = node->prev;
            Node *b = node->next;
            a->next = b;
            b->prev = a;
        }
    }

    void print() {
        Node *node = front;
        while (node != NULL) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }

    Node* find_node(int data) {
        Node *node = front;
        while (node != NULL) {
            if (node->data == data)
                return node;
            node = node->next; 
        }
        return NULL;
    }

    void insert_node(Node *node1, int data) {
        Node *node = new Node(data);
        if (node1 == tail) 
            push_back(data);
        else {
            Node *node2 = node1->next;
            node1->next = node;
            node->prev = node1;
            node->next = node2;
            node2->prev = node;
        }
    }
};

int main() {
    LinkedList *ll = new LinkedList();
    ll->push_back(5);
    ll->push_back(6);
    ll->push_back(7);
    ll->push_back(8);
    ll->push_back(9);
    ll->push_back(10);
    ll->push_front(11);
    ll->push_front(12);
    ll->push_front(13);
    ll->push_front(14);
    ll->push_front(15);
    ll->print();
    cout << ll->front->data << " " << ll->tail->data << endl;
    ll->pop_back(); 
    ll->pop_back();
    ll->pop_front(); 
    ll->pop_front();
    ll->print();
    cout << ll->front->data << " " << ll->tail->data << endl;

    Node *node = ll->find_node(11);
    if (node != NULL) {
        ll->del_node(node);
    }

    ll->print();

    node = ll->find_node(6);
    ll->insert_node(node, 100);
    ll->print();
    return 0;
}