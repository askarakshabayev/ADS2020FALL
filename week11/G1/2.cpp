#include <iostream>

using namespace std;

class Node {
    public:
    char value;
    Node *ch[26];

    Node(char value) {
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
            } else {
                Node *node = new Node(s[i]);
                cur->ch[s[i] - 'a'] = node;
                cur = node;
                cnt++;
            }
        }
    }
};

int main() {
    Trie *trie = new Trie();
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        trie->insert(s.substr(i));
    }
    cout << trie->cnt;
    return 0;
}