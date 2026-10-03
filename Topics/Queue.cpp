// Queue

#include <iostream>
using namespace std;


// ============================================================
//              QUEUE USING ARRAY
// ============================================================

class QueueArray
{
private:
    int arr[5];
    int front;
    int rear;

public:

    // Constructor
    QueueArray()
    {
        front = -1;
        rear = -1;
    }

    // --------------------------------------------------------
    // ENQUEUE: Add element at the REAR
    // --------------------------------------------------------
    void enqueue(int value)
    {
        // Queue is full
        if (rear == 4)
        {
            cout << "Array Queue Overflow\n";
            return;
        }

        // First element
        if (front == -1)
        {
            front = 0;
        }

        rear++;
        arr[rear] = value;
    }

    // --------------------------------------------------------
    // DEQUEUE: Remove element from the FRONT
    // --------------------------------------------------------
    void dequeue()
    {
        // Queue is empty
        if (front == -1 || front > rear)
        {
            cout << "Array Queue Underflow\n";
            return;
        }

        cout << "Removed: " << arr[front] << endl;

        front++;
    }

    // --------------------------------------------------------
    // PEEK: Show the front element
    // --------------------------------------------------------
    void peek()
    {
        if (front == -1 || front > rear)
        {
            cout << "Array Queue is empty\n";
            return;
        }

        cout << "Front: " << arr[front] << endl;
    }

    // --------------------------------------------------------
    // DISPLAY: Show all elements
    // --------------------------------------------------------
    void display()
    {
        if (front == -1 || front > rear)
        {
            cout << "Array Queue is empty\n";
            return;
        }

        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};


// ============================================================
//              QUEUE USING LINKED LIST
// ============================================================

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};


class QueueLL
{
private:
    Node* front;
    Node* rear;

public:

    // Constructor
    QueueLL()
    {
        front = NULL;
        rear = NULL;
    }

    // --------------------------------------------------------
    // ENQUEUE: Add node at the REAR
    // --------------------------------------------------------
    void enqueue(int value)
    {
        Node* newNode = new Node(value);

        // If queue is empty
        if (front == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            // Add new node at rear
            rear->next = newNode;
            rear = newNode;
        }
    }

    // --------------------------------------------------------
    // DEQUEUE: Remove node from the FRONT
    // --------------------------------------------------------
    void dequeue()
    {
        // Queue is empty
        if (front == NULL)
        {
            cout << "LL Queue Underflow\n";
            return;
        }

        Node* temp = front;

        cout << "Removed: " << front->data << endl;

        // Move front to next node
        front = front->next;

        // If queue becomes empty
        if (front == NULL)
        {
            rear = NULL;
        }

        delete temp;
    }

    // --------------------------------------------------------
    // PEEK: Show the front element
    // --------------------------------------------------------
    void peek()
    {
        if (front == NULL)
        {
            cout << "LL Queue is empty\n";
            return;
        }

        cout << "Front: " << front->data << endl;
    }

    // --------------------------------------------------------
    // DISPLAY: Show all nodes
    // --------------------------------------------------------
    void display()
    {
        if (front == NULL)
        {
            cout << "LL Queue is empty\n";
            return;
        }

        Node* temp = front;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};


// ============================================================
//                         MAIN
// ============================================================

int main()
{
    // ========================================================
    // ARRAY QUEUE
    // ========================================================

    cout << "===== QUEUE USING ARRAY =====\n";

    QueueArray q1;

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);

    cout << "Queue: ";
    q1.display();

    q1.peek();

    q1.dequeue();

    cout << "Queue after dequeue: ";
    q1.display();


    // ========================================================
    // LINKED LIST QUEUE
    // ========================================================

    cout << "\n===== QUEUE USING LINKED LIST =====\n";

    QueueLL q2;

    q2.enqueue(10);
    q2.enqueue(20);
    q2.enqueue(30);

    cout << "Queue: ";
    q2.display();

    q2.peek();

    q2.dequeue();

    cout << "Queue after dequeue: ";
    q2.display();


    return 0;
}


