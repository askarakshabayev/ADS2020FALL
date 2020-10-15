#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {
    public:
    Node *root;
    BST() {
        root = NULL;
    }

    Node* insert(Node *node, int data) {
        if (node == NULL) {
            node = new Node(data);
            return node;
        }

        if (data <= node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }

    void inOrder(Node *node) {
        if (node == NULL)
            return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    Node *findMin(Node *node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    Node *findMax(Node *node) {
        while (node->right != NULL)
            node = node->right;
        return node;
    }

    Node *deleteNode(Node *node, int data) {
        if (node == NULL)
            return NULL;
        if (data < node->data)
            node->left = deleteNode(node->left, data);
        else if (data > node->data) 
            node->right = deleteNode(node->right, data);
        else {
            if (node->left == NULL && node->right == NULL)
                return NULL;
            else if (node->left == NULL) 
                node = node->right;
            else if (node->right == NULL)
                node = node->left;
            else {
                Node *tmp = findMax(node->left);
                node->data = tmp->data;
                node->left = deleteNode(node->left, tmp->data);                
            }
        }
        return node;
    }
};

int main() {
    BST *bst = new BST();
    bst->root = bst->insert(bst->root, 15);
    bst->root = bst->insert(bst->root, 6);
    bst->root = bst->insert(bst->root, 18);
    bst->root = bst->insert(bst->root, 3);
    bst->root = bst->insert(bst->root, 11);
    bst->root = bst->insert(bst->root, 8);
    bst->root = bst->insert(bst->root, 25);
    bst->root = bst->insert(bst->root, 14);
    bst->root = bst->insert(bst->root, 6);
    bst->root = bst->insert(bst->root, 36);
    bst->inOrder(bst->root->right);
    cout << endl;
    cout << bst->findMin(bst->root)->data << endl;
    cout << bst->findMax(bst->root)->data << endl;

    return 0;
}