#include <iostream>

using namespace std;
const int N = 26;

class Node {
    public:
    char value;
    Node *ch[N];
    int cnt;
    Node(char value) {
        this->value = value;
        for (int i = 0; i < N; i++)
            ch[i] = NULL;
        cnt = 1;
    }
};

class Trie {
    public:
    Node *root;
    Trie() {
        root = new Node(' ');
    }

    void insert(string s) {
        Node *cur = root;
        for (int i = 0; i < s.size(); i++) {
            if (cur->ch[s[i] - 'a'] != NULL) {
                cur = cur->ch[s[i] - 'a'];
                cur->cnt++;
            }
            else {
                Node *node = new Node(s[i]);
                cur->ch[s[i] - 'a'] = node;
                cur = node;
            }
        }
    }

    void search(Node *node, string s) {
        if (s != "")
            cout << s << " - " << node->cnt << endl;

        for (int i = 0; i < N; i++)
            if (node->ch[i] != NULL) {
                search(node->ch[i], s + node->ch[i]->value);
            }
    }

};

int main() {
    int n;
    cin >> n;
    Trie *trie = new Trie();
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        trie->insert(s);
    }
    trie->search(trie->root, "");
    return 0;
}