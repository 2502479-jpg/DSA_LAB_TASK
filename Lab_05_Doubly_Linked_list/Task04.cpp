#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string song;
    Node* next;

    Node(string s) {
        song = s;
        next = NULL;
    }
};

class Playlist {
    Node* head;
    Node* tail;
    int count;

public:
    Playlist() {
        head = NULL;
        tail = NULL;
        count = 0;
    }

    void addSong(string name) {
        Node* n = new Node(name);
        if (head == NULL) {
            head = tail = n;
            tail->next = head;      // points to itself
        } else {
            tail->next = n;
            tail = n;
            tail->next = head;      // circular, no NULL
        }
        count++;
    }

    void showAll() {
        cout << "Playlist (all songs once):" << endl;
        Node* cur = head;
        do {
            cout << cur->song << endl;
            cur = cur->next;
        } while (cur != head);
    }

    void playRounds(int rounds) {
        Node* cur = head;
        for (int r = 1; r <= rounds; r++) {
            cout << "\n--- Round " << r << " ---" << endl;
            for (int i = 0; i < count; i++) {
                cout << "Playing: " << cur->song << endl;
                cur = cur->next;    // after last song, goes back to first
            }
        }
    }
};

int main() {
    Playlist p;
    p.addSong("Song A");
    p.addSong("Song B");
    p.addSong("Song C");
    p.addSong("Song D");
    p.addSong("Song E");

    p.showAll();
    p.playRounds(2);
    return 0;
}