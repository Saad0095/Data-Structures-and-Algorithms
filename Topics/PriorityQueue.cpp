// https://chatgpt.com/share/6ac15b45-1b8c-83ec-8403-67db28c27c19

// Using STL

// Here, C++ automatically treats the integer value itself as the priority.
// #include <iostream>
// #include <queue>
// using namespace std;

// int main()
// {

//     priority_queue<int> pq;

//     // Insert elements
//     pq.push(30);
//     pq.push(10);
//     pq.push(50);
//     pq.push(20);

//     // Highest priority element
//     cout << "Top: " << pq.top() << endl;

//     // Remove elements
//     while (!pq.empty())
//     {
//         cout << pq.top() << " ";
//         pq.pop();
//     }

//     // For priority_queue<int>:

//     // 50 → 30 → 20 → 10
//     // ↑
//     // Highest priority
//     return 0;
// }


// ** Using LinkedList

#include <iostream>
using namespace std;

struct Node {
    int data;
    int priority;
    Node* next;

    Node(int d, int p) {
        data = d;
        priority = p;
        next = nullptr;
    }
};

class PriorityQueue {
private:
    Node* front;

public:
    PriorityQueue() {
        front = nullptr;
    }

    void push(int data, int priority) {
        Node* newNode = new Node(data, priority);

        // Empty queue OR new node has higher priority
        if (front == nullptr || priority > front->priority) {
            newNode->next = front;
            front = newNode;
            return;
        }

        // Find correct position
        Node* temp = front;

        while (temp->next != nullptr &&
               temp->next->priority >= priority) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop() {
        if (front == nullptr) {
            cout << "Priority Queue is empty\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        delete temp;
    }

    int top() {
        if (front == nullptr) {
            cout << "Priority Queue is empty\n";
            return -1;
        }

        return front->data;
    }

    void display() {
        Node* temp = front;

        while (temp != nullptr) {
            cout << "(" << temp->data
                 << ", P" << temp->priority << ") ";

            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {

    PriorityQueue pq;

    pq.push(10, 2);
    pq.push(20, 5);
    pq.push(30, 1);
    pq.push(40, 4);

    pq.display();

    cout << "Top: " << pq.top() << endl;

    pq.pop();

    cout << "After pop: ";
    pq.display();

    return 0;
}

