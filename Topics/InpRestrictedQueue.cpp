// https://chatgpt.com/share/6ac15bb6-4b64-83ec-bef0-eb5a887fc07f

#include <iostream>
using namespace std;

class InputRestrictedQueue {
private:
    int arr[5];
    int front;
    int rear;
    int size;

public:
    InputRestrictedQueue() {
        front = -1;
        rear = -1;
        size = 5;
    }

    // Insertion is ONLY allowed at rear
    void insert(int value) {
        if (rear == size - 1) {
            cout << "Queue is full!" << endl;
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear++;
        arr[rear] = value;

        cout << value << " inserted." << endl;
    }

    // Delete from front
    void deleteFront() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << arr[front] << " deleted from front." << endl;
        front++;
    }

    // Delete from rear
    void deleteRear() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << arr[rear] << " deleted from rear." << endl;
        rear--;
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue: ";

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    InputRestrictedQueue q;

    q.insert(10);
    q.insert(20);
    q.insert(30);

    q.display();

    q.deleteFront();
    q.display();

    q.deleteRear();
    q.display();

    return 0;
}


// Using LL


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class InputRestrictedQueue {
private:
    Node* front;
    Node* rear;

public:
    InputRestrictedQueue() {
        front = nullptr;
        rear = nullptr;
    }

    // Insert ONLY at rear
    void insert(int value) {
        Node* newNode = new Node(value);

        // Empty queue
        if (front == nullptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    // Delete from front
    void deleteFront() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }
        else {
            front->prev = nullptr;
        }

        delete temp;
    }

    // Delete from rear
    void deleteRear() {
        if (rear == nullptr) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = rear;
        rear = rear->prev;

        if (rear == nullptr) {
            front = nullptr;
        }
        else {
            rear->next = nullptr;
        }

        delete temp;
    }

    void display() {
        Node* temp = front;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    InputRestrictedQueue q;

    q.insert(10);
    q.insert(20);
    q.insert(30);

    q.display();

    q.deleteFront();
    q.display();

    q.deleteRear();
    q.display();

    return 0;
}