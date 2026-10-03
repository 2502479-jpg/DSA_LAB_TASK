#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string image;
    Node* prev;
    Node* next;

    Node(string img) {
        image = img;
        prev = NULL;
        next = NULL;
    }
};

class Gallery {
    Node* head;
    Node* tail;

public:
    Gallery() {
        head = NULL;
        tail = NULL;
    }

    void addImage(string img) {
        Node* n = new Node(img);
        if (head == NULL) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    void showForward() {
        cout << "Gallery (first -> last):" << endl;
        for (Node* cur = head; cur != NULL; cur = cur->next)
            cout << cur->image << endl;
    }

    void showBackward() {
        cout << "\nGallery (last -> first):" << endl;
        for (Node* cur = tail; cur != NULL; cur = cur->prev)
            cout << cur->image << endl;
    }

    // Demonstrates movement in both directions using prev and next
    void demoNavigation() {
        cout << "\nNavigation demo:" << endl;
        Node* cur = head->next->next;   // start at the 3rd image
        cout << "Current:  " << cur->image << endl;

        cur = cur->next;                // move forward
        cout << "Next:     " << cur->image << endl;

        cur = cur->prev->prev;          // move back two steps
        cout << "Back x2:  " << cur->image << endl;
    }
};

int main() {
    Gallery g;
    g.addImage("sunset.jpg");
    g.addImage("mountain.png");
    g.addImage("beach.jpg");
    g.addImage("forest.png");
    g.addImage("city.jpg");

    g.showForward();
    g.showBackward();
    g.demoNavigation();
    return 0;
}