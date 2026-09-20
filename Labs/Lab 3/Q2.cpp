// deuque -> from front (start)
// enqueue -> from rear (end)

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val = 0) : data(val), next(NULL), prev(NULL) {};
};

class CircularQueue
{
private:
    Node *front;
    Node *rear;

public:
    CircularQueue()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueueRear(int val)
    {
        Node *newNode = new Node(val);
        if (front == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    int dequeueFront()
    {
        if (front == NULL)
        {
            return -1;
        }

        int val = front->data;

        if (front == rear)
        {
            delete front;
            front = rear = NULL;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            front->prev = NULL;
            delete temp;
        }
        return val;
    }

    void enqueueFront(int val)
    {
        Node *newNode = new Node(val);
        if (front == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    int dequeueRear()
    {
        if (front == NULL)
        {
            return -1;
        }

        int val = rear->data;

        if (front == rear)
        {
            delete front;
            front = rear = NULL;
        }
        else
        {
            Node *temp = rear;
            rear = rear->prev;
            rear->next = NULL;
            delete temp;
        }
        return val;
    }

    void display()
    {
        Node *temp = front;

        if (front == nullptr)
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != NULL);
        cout << endl;
    }
};

int main()
{
    CircularQueue q;
    q.enqueueRear(10);
    q.enqueueRear(20);
    q.enqueueRear(30);
    q.display();

    q.enqueueFront(5);
    q.display();

    cout << "Deleted from front: "
         << q.dequeueFront() << endl;
    q.display();

    cout << "Deleted from rear: "
         << q.dequeueRear() << endl;

    q.display();

    return 0;
}