// Circular Queue

#include <iostream>
using namespace std;


// ============================================================
//              CIRCULAR QUEUE USING ARRAY
// ============================================================

class CircularQueueArray
{
private:
    int arr[5];
    int front;
    int rear;
    int size;

public:

    // Constructor
    CircularQueueArray()
    {
        front = -1;
        rear = -1;
        size = 0;
    }

    // --------------------------------------------------------
    // ENQUEUE: Add element at the REAR
    // --------------------------------------------------------
    void enqueue(int value)
    {
        // Queue is full
        if (size == 5)
        {
            cout << "Circular Queue Overflow\n";
            return;
        }

        // First element
        if (front == -1)
        {
            front = 0;
        }

        // Move rear circularly
        rear = (rear + 1) % 5;

        arr[rear] = value;

        size++;
    }

    // --------------------------------------------------------
    // DEQUEUE: Remove element from the FRONT
    // --------------------------------------------------------
    void dequeue()
    {
        // Queue is empty
        if (size == 0)
        {
            cout << "Circular Queue Underflow\n";
            return;
        }

        cout << "Removed: " << arr[front] << endl;

        // Move front circularly
        front = (front + 1) % 5;

        size--;

        // If queue becomes empty
        if (size == 0)
        {
            front = -1;
            rear = -1;
        }
    }

    // --------------------------------------------------------
    // PEEK: Show the front element
    // --------------------------------------------------------
    void peek()
    {
        if (size == 0)
        {
            cout << "Circular Queue is empty\n";
            return;
        }

        cout << "Front: " << arr[front] << endl;
    }

    // --------------------------------------------------------
    // DISPLAY: Show all elements
    // --------------------------------------------------------
    void display()
    {
        if (size == 0)
        {
            cout << "Circular Queue is empty\n";
            return;
        }

        int index = front;

        for (int i = 0; i < size; i++)
        {
            cout << arr[index] << " ";

            // Move circularly
            index = (index + 1) % 5;
        }

        cout << endl;
    }
};


// ============================================================
//              CIRCULAR QUEUE USING LINKED LIST
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


class CircularQueueLL
{
private:
    Node* front;
    Node* rear;

public:

    // Constructor
    CircularQueueLL()
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

            // Last node points back to front
            rear->next = front;
        }
        else
        {
            // Add new node after rear
            rear->next = newNode;

            // Move rear to new node
            rear = newNode;

            // Rear points back to front
            rear->next = front;
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
            cout << "Circular LL Queue Underflow\n";
            return;
        }

        // Only one node
        if (front == rear)
        {
            cout << "Removed: " << front->data << endl;

            delete front;

            front = NULL;
            rear = NULL;
        }
        else
        {
            Node* temp = front;

            cout << "Removed: " << front->data << endl;

            // Move front to next node
            front = front->next;

            // Rear still points to front
            rear->next = front;

            delete temp;
        }
    }

    // --------------------------------------------------------
    // PEEK: Show the front element
    // --------------------------------------------------------
    void peek()
    {
        if (front == NULL)
        {
            cout << "Circular LL Queue is empty\n";
            return;
        }

        cout << "Front: " << front->data << endl;
    }

    // --------------------------------------------------------
    // DISPLAY: Show all elements
    // --------------------------------------------------------
    void display()
    {
        if (front == NULL)
        {
            cout << "Circular LL Queue is empty\n";
            return;
        }

        Node* temp = front;

        // Because it is circular, we cannot use:
        // while (temp != NULL)

        do
        {
            cout << temp->data << " ";
            temp = temp->next;

        } while (temp != front);

        cout << endl;
    }
};


// ============================================================
//                         MAIN
// ============================================================

int main()
{
    // ========================================================
    // CIRCULAR QUEUE USING ARRAY
    // ========================================================

    cout << "===== CIRCULAR QUEUE USING ARRAY =====\n";

    CircularQueueArray q1;

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);

    cout << "Queue: ";
    q1.display();

    q1.peek();

    q1.dequeue();
    q1.dequeue();

    cout << "Queue after dequeue: ";
    q1.display();

    // These will reuse the empty spaces
    q1.enqueue(60);
    q1.enqueue(70);

    cout << "Queue after adding 60 and 70: ";
    q1.display();


    // ========================================================
    // CIRCULAR QUEUE USING LINKED LIST
    // ========================================================

    cout << "\n===== CIRCULAR QUEUE USING LINKED LIST =====\n";

    CircularQueueLL q2;

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