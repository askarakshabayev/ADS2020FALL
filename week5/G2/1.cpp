// 5 2
// the -> show -> must -> go -> on -> null

#include <iostream>
using namespace std;

struct Node {
	string word;
	Node* next;

	Node() {}

	Node(string word) {
		this->word = word;
		this->next = NULL;
	}
};

// your code goes here

Node* cyclicShift(Node* head, int k) {
    // 
    // the  ->   show  must -> go -> on -> head 
    // head                         
    //                   nh    
    //            nt
    //                                 tail 

    Node *new_head = head;          
    Node *new_tail = NULL;
    for (int i = 0; i < k; i++) {
        new_tail = new_head;
        new_head = new_head->next;
    }
    Node *tail = head;
    while (tail->next != NULL)
        tail = tail->next;
    
    tail->next = head;
    new_tail->next = NULL;

    return new_head;
}

void print(Node* head) {
	Node* cur = head;
	while (cur != NULL) {
		cout << cur->word << " ";
		cur = cur->next;
	}
	cout << endl;
}

int main() {
	int n; cin >> n; // 5
	int k; cin >> k; // 2
	Node* head;
	Node* cur;
	for (int i = 0; i < n; i++) {
		string word; 
        cin >> word;
		if (i == 0) {
			head = new Node(word);
			cur = head;
		} else {
			cur->next = new Node(word);
			cur = cur->next;
		}
	}

	head = cyclicShift(head, k);
	print(head);
}
