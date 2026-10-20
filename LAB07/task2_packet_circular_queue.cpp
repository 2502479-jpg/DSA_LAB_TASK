#include <iostream>
using namespace std;

#define SIZE 5

class PacketQueue {
    int arr[SIZE];
    int front, rear;

public:
    PacketQueue() : front(-1), rear(-1) {}

    bool isEmpty() { return front == -1; }
    bool isFull()  { return (rear + 1) % SIZE == front; }

    void enqueue(int id) {
        if (isFull()) {
            cout << "Queue FULL! Packet " << id << " dropped.\n";
            return;
        }
        if (isEmpty()) front = rear = 0;
        else rear = (rear + 1) % SIZE;   // wraps around to reuse empty slots
        arr[rear] = id;
        cout << "Packet " << id << " stored at position " << rear << ".\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue EMPTY! No packet to transmit.\n";
            return;
        }
        cout << "Transmitted packet " << arr[front] << ".\n";
        if (front == rear) front = rear = -1;   // queue became empty
        else front = (front + 1) % SIZE;
    }

    void display() {
        if (isEmpty()) {
            cout << "No packets waiting.\n";
            return;
        }
        cout << "Waiting packets (front -> rear): ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << "\n";
    }
};

int main() {
    PacketQueue q;
    int choice, id;

    do {
        cout << "\n--- Network Packet Buffer ---\n"
             << "1. Insert packet\n"
             << "2. Transmit packet\n"
             << "3. Display waiting packets\n"
             << "0. Exit\n"
             << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter packet ID: ";
                cin >> id;
                q.enqueue(id);
                break;
            case 2: q.dequeue(); break;
            case 3: q.display(); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
