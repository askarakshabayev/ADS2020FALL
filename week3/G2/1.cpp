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
    Node *front, *tail;

    LinkedList() {
        front = NULL;
        tail = NULL;
    }

    void push_back(int data) {
        Node *node = new Node(data);
        if (tail == NULL) {
            front = node;
            tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void push_front(int data) {
        Node *node = new Node(data);
        if (front == NULL) {
            front = node;
            tail = node;            
        } else {
            node->next = front;
            front->prev = node;
            front = node;
        }
    }

    void pop_back() {
        if (tail == NULL)
            return;
        tail = tail->prev;
        
        if (tail != NULL)
            tail->next = NULL;
        else
            front = NULL; 
    }

    void pop_front() {
        if (front == NULL)
            return;
        front = front->next;
        if (front != NULL)
            front->prev = NULL;
        else 
            tail = NULL;
    }

    void print() {
        Node *node = front;
        while (node != NULL) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }

    Node *find_node(int data) {
        Node *node = front;
        while (node != NULL) {
            if (node->data == data)
                return node;
            node = node->next;            
        }
        return NULL;
    }

    void insert_node(Node *a, int data) {
        if (a == tail) 
            push_back(data);
        else {
            Node *b = a->next;
            Node *node = new Node(data);
            a->next = node;
            node->prev = a;
            node->next = b;
            b->prev = node;
        }
    }

    void delete_node(Node *node) {
        if (node == tail)
            this->pop_back();
        else if (node == front)
            this->pop_front();
        else {
            Node *a = node->prev;
            Node *b = node->next;
            a->next = b;
            b->prev = a;
        }
    }
};

int main() {
    LinkedList *ll = new LinkedList();
    ll->push_back(5); 
    ll->push_back(10);
    ll->push_front(20);
    ll->push_front(30);
    ll->print(); // 30 20 45 5 10
    Node *node = ll->find_node(20);
    if (node != NULL) {
        ll->insert_node(node, 45);
        ll->print();
    }
    node = ll->find_node(5);
    delete node;
    ll->delete_node(node);
    ll->print();

    return 0;
}