#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string player;
    Node* next;

    Node(string p) {
        player = p;
        next = NULL;
    }
};

class Game {
    Node* head;
    Node* tail;

public:
    Game() {
        head = NULL;
        tail = NULL;
    }

    void addPlayer(string name) {
        Node* n = new Node(name);
        if (head == NULL) {
            head = tail = n;
            tail->next = head;      // points to itself
        } else {
            tail->next = n;
            tail = n;
            tail->next = head;      // circular connection
        }
    }

    void showTurns() {
        cout << "Each player's turn:" << endl;
        Node* cur = head;
        int turn = 1;
        do {
            cout << "Turn " << turn++ << ": " << cur->player << endl;
            cur = cur->next;
        } while (cur != head);
    }

    void showWrapAround() {
        cout << "\nAfter the last player:" << endl;
        cout << "Last player:  " << tail->player << endl;
        cout << "Next turn is: " << tail->next->player << endl;
    }
};

int main() {
    Game g;
    g.addPlayer("Areeb");
    g.addPlayer("Ali");
    g.addPlayer("Sara");
    g.addPlayer("Hamza");
    g.addPlayer("Zainab");

    g.showTurns();
    g.showWrapAround();
    return 0;
}