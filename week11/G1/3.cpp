#include <iostream>

using namespace std;
const int N = 26;

class Node {
    public:
    char value;
    int cnt;
    Node *ch[N];

    Node(char value) {
        cnt = 1;
        this->value = value;
        for (int i = 0; i < 26; i++)
            ch[i] = NULL;
    }
};

class Trie {
    public:
    int cnt;
    Node *root;
    Trie() {
        root = new Node(' ');
        cnt = 0;
    }

    void insert(string s) {
        Node *cur = root;
        for (int i = 0; i < s.size(); i++) {
            if (cur->ch[s[i] - 'a'] != NULL) {
                cur = cur->ch[s[i] - 'a'];
                cur->cnt++;
            } else {
                Node *node = new Node(s[i]);
                cur->ch[s[i] - 'a'] = node;
                cur = node;
            }
        }
    }

    void search(Node *node, string s) {
        if (node != root) {
            cout << s << " - " << node->cnt << endl;
        }
        for (int i = 0; i < N; i++)
            if (node->ch[i] != NULL)
                search(node->ch[i], s + node->ch[i]->value);
    }
};

int main() {
    Trie *trie = new Trie();
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        trie->insert(s);
    }
    trie->search(trie->root, "");
    return 0;
}