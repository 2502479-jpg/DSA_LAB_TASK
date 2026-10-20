#include <iostream>
using namespace std;

#define SIZE 5

class TrainDeque {
    int arr[SIZE];
    int front, count;

public:
    TrainDeque() : front(0), count(0) {}

    bool isEmpty() { return count == 0; }
    bool isFull()  { return count == SIZE; }

    void insertFront(int id) {
        if (isFull()) {
            cout << "Deque FULL! Cannot insert " << id << " at front.\n";
            return;
        }
        front = (front - 1 + SIZE) % SIZE;
        arr[front] = id;
        count++;
        cout << "Request " << id << " inserted at front.\n";
    }

    void insertRear(int id) {
        if (isFull()) {
            cout << "Deque FULL! Cannot insert " << id << " at rear.\n";
            return;
        }
        arr[(front + count) % SIZE] = id;
        count++;
        cout << "Request " << id << " inserted at rear.\n";
    }

    void removeFront() {
        if (isEmpty()) {
            cout << "Deque EMPTY! Nothing to remove from front.\n";
            return;
        }
        cout << "Removed request " << arr[front] << " from front.\n";
        front = (front + 1) % SIZE;
        count--;
    }

    void removeRear() {
        if (isEmpty()) {
            cout << "Deque EMPTY! Nothing to remove from rear.\n";
            return;
        }
        int rear = (front + count - 1) % SIZE;
        cout << "Removed request " << arr[rear] << " from rear.\n";
        count--;
    }

    void display() {
        if (isEmpty()) {
            cout << "No requests waiting.\n";
            return;
        }
        cout << "Front -> ";
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % SIZE];
            if (i < count - 1) cout << ", ";
        }
        cout << " <- Rear\n";
    }
};

int main() {
    TrainDeque d;
    int choice, id;

    do {
        cout << "\n--- Train Station Passenger Requests ---\n"
             << "1. Insert at front\n"
             << "2. Insert at rear\n"
             << "3. Remove from front\n"
             << "4. Remove from rear\n"
             << "5. Display requests\n"
             << "0. Exit\n"
             << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter request ID: ";
                cin >> id;
                d.insertFront(id);
                break;
            case 2:
                cout << "Enter request ID: ";
                cin >> id;
                d.insertRear(id);
                break;
            case 3: d.removeFront(); break;
            case 4: d.removeRear(); break;
            case 5: d.display(); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
