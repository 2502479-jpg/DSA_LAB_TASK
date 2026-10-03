#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string site;
    Node* prev;
    Node* next;

    Node(string s) {
        site = s;
        prev = NULL;
        next = NULL;
    }
};

class BrowserHistory {
    Node* head;
    Node* tail;

public:
    BrowserHistory() {
        head = NULL;
        tail = NULL;
    }

    void visit(string site) {
        Node* n = new Node(site);
        if (head == NULL) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    void showForward() {
        cout << "History (first -> last):" << endl;
        for (Node* cur = head; cur != NULL; cur = cur->next)
            cout << cur->site << endl;
    }

    void showBackward() {
        cout << "\nHistory (last -> first):" << endl;
        for (Node* cur = tail; cur != NULL; cur = cur->prev)
            cout << cur->site << endl;
    }
};

int main() {
    BrowserHistory h;
    h.visit("google.com");
    h.visit("youtube.com");
    h.visit("github.com");
    h.visit("stackoverflow.com");
    h.visit("wikipedia.org");

    h.showForward();
    h.showBackward();
    return 0;
}