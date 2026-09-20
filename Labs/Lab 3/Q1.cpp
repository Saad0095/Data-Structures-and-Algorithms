// deuque -> from front (start)
// enqueue -> from rear (end)

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val = 0) : data(val), next(NULL) {};
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

    void enqueue(int val)
    {
        Node *newNode = new Node(val);
        if (front == NULL)
        {
            front = rear = newNode;
            rear->next = front;
        }
        else
        {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue()
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
            rear->next = front;
            delete temp;
        }
        return val;
    }

    void display()
    {
        Node *temp = front;

        if (front == nullptr) {
            cout << "Queue is Empty" << endl;
            return;
        }

        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (front != temp);
        cout << endl;
    }
};

int main()
{
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    return 0;
}