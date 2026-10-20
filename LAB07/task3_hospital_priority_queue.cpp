#include <iostream>
#include <string>
using namespace std;

#define SIZE 10

// Priority rule: smaller number = higher urgency (1 is the highest).
// Patients with equal priority are treated in arrival order.
struct Patient {
    string id;
    int priority;
};

class EmergencyQueue {
    Patient arr[SIZE];
    int count;

public:
    EmergencyQueue() : count(0) {}

    bool isEmpty() { return count == 0; }
    bool isFull()  { return count == SIZE; }

    void insert(string id, int priority) {
        if (isFull()) {
            cout << "Queue FULL! Cannot admit patient " << id << ".\n";
            return;
        }
        // Keep the array sorted: shift lower-urgency patients to the right
        int i = count - 1;
        while (i >= 0 && arr[i].priority > priority) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = {id, priority};
        count++;
        cout << "Patient " << id << " admitted with priority " << priority << ".\n";
    }

    void treat() {
        if (isEmpty()) {
            cout << "Queue EMPTY! No patients waiting.\n";
            return;
        }
        cout << "Treating patient " << arr[0].id
             << " (priority " << arr[0].priority << ").\n";
        for (int i = 1; i < count; i++) arr[i - 1] = arr[i];
        count--;
    }

    void display() {
        if (isEmpty()) {
            cout << "No patients waiting.\n";
            return;
        }
        cout << "Waiting patients (most urgent first):\n";
        for (int i = 0; i < count; i++)
            cout << "  " << arr[i].id << "  | Priority: " << arr[i].priority << "\n";
    }
};

int main() {
    EmergencyQueue q;
    int choice, priority;
    string id;

    do {
        cout << "\n--- Hospital Emergency Department ---\n"
             << "1. Insert patient\n"
             << "2. Treat next patient\n"
             << "3. Display waiting patients\n"
             << "0. Exit\n"
             << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter patient ID (e.g. P101): ";
                cin >> id;
                cout << "Enter priority (1 = highest): ";
                cin >> priority;
                q.insert(id, priority);
                break;
            case 2: q.treat(); break;
            case 3: q.display(); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
