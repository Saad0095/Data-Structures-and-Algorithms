#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularQueue {
    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = rear = NULL;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);

        if (front == NULL) {
            front = rear = newNode;
            rear->next = front;
        }
        else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty"<<endl;
            return;
        }

        if (front == rear) {
            delete front;
            front = rear = NULL;
        }
        else {
            Node* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty"<<endl;
            return;
        }

        Node* temp = front;

        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != front);
        
        cout << front -> data << endl;
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();

    q.display();

    return 0;
}