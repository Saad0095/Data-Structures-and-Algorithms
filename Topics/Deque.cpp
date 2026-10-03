#include <iostream>
using namespace std;


// ============================================================
//                    DEQUE USING ARRAY
// ============================================================

class DequeArray
{
private:
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;

public:

    // Constructor
    // User decides the size of the array
    DequeArray(int capacity)
    {
        this->capacity = capacity;

        arr = new int[capacity];

        front = -1;
        rear = -1;
        size = 0;
    }

    // --------------------------------------------------------
    // INSERT AT FRONT
    // --------------------------------------------------------
    void insertFront(int value)
    {
        // Check if deque is full
        if (size == capacity)
        {
            cout << "Deque Overflow\n";
            return;
        }

        // First element
        if (size == 0)
        {
            front = rear = 0;
        }
        else
        {
            // Move front backwards circularly
            front = (front - 1 + capacity) % capacity;
        }

        arr[front] = value;
        size++;
    }

    // --------------------------------------------------------
    // INSERT AT REAR
    // --------------------------------------------------------
    void insertRear(int value)
    {
        // Check if deque is full
        if (size == capacity)
        {
            cout << "Deque Overflow\n";
            return;
        }

        // First element
        if (size == 0)
        {
            front = rear = 0;
        }
        else
        {
            // Move rear forward circularly
            rear = (rear + 1) % capacity;
        }

        arr[rear] = value;
        size++;
    }

    // --------------------------------------------------------
    // DELETE FROM FRONT
    // --------------------------------------------------------
    void deleteFront()
    {
        // Check if deque is empty
        if (size == 0)
        {
            cout << "Deque Underflow\n";
            return;
        }

        cout << "Deleted: " << arr[front] << endl;

        // Only one element
        if (size == 1)
        {
            front = rear = -1;
        }
        else
        {
            // Move front forward
            front = (front + 1) % capacity;
        }

        size--;
    }

    // --------------------------------------------------------
    // DELETE FROM REAR
    // --------------------------------------------------------
    void deleteRear()
    {
        // Check if deque is empty
        if (size == 0)
        {
            cout << "Deque Underflow\n";
            return;
        }

        cout << "Deleted: " << arr[rear] << endl;

        // Only one element
        if (size == 1)
        {
            front = rear = -1;
        }
        else
        {
            // Move rear backwards
            rear = (rear - 1 + capacity) % capacity;
        }

        size--;
    }

    // --------------------------------------------------------
    // GET FRONT
    // --------------------------------------------------------
    void getFront()
    {
        if (size == 0)
        {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Front: " << arr[front] << endl;
    }

    // --------------------------------------------------------
    // GET REAR
    // --------------------------------------------------------
    void getRear()
    {
        if (size == 0)
        {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Rear: " << arr[rear] << endl;
    }

    // --------------------------------------------------------
    // DISPLAY
    // --------------------------------------------------------
    void display()
    {
        if (size == 0)
        {
            cout << "Deque is empty\n";
            return;
        }

        int index = front;

        for (int i = 0; i < size; i++)
        {
            cout << arr[index] << " ";

            // Move circularly
            index = (index + 1) % capacity;
        }

        cout << endl;
    }

    // Destructor
    ~DequeArray()
    {
        delete[] arr;
    }
};


// ============================================================
//                  DEQUE USING LINKED LIST
// ============================================================

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};


class DequeLL
{
private:
    Node* front;
    Node* rear;

public:

    // Constructor
    DequeLL()
    {
        front = NULL;
        rear = NULL;
    }

    // --------------------------------------------------------
    // INSERT AT FRONT
    // --------------------------------------------------------
    void insertFront(int value)
    {
        Node* newNode = new Node(value);

        // If deque is empty
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

    // --------------------------------------------------------
    // INSERT AT REAR
    // --------------------------------------------------------
    void insertRear(int value)
    {
        Node* newNode = new Node(value);

        // If deque is empty
        if (rear == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            newNode->prev = rear;
            rear->next = newNode;

            rear = newNode;
        }
    }

    // --------------------------------------------------------
    // DELETE FROM FRONT
    // --------------------------------------------------------
    void deleteFront()
    {
        // Check if empty
        if (front == NULL)
        {
            cout << "Deque Underflow\n";
            return;
        }

        Node* temp = front;

        cout << "Deleted: " << front->data << endl;

        // Only one node
        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
            front->prev = NULL;
        }

        delete temp;
    }

    // --------------------------------------------------------
    // DELETE FROM REAR
    // --------------------------------------------------------
    void deleteRear()
    {
        // Check if empty
        if (rear == NULL)
        {
            cout << "Deque Underflow\n";
            return;
        }

        Node* temp = rear;

        cout << "Deleted: " << rear->data << endl;

        // Only one node
        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            rear = rear->prev;
            rear->next = NULL;
        }

        delete temp;
    }

    // --------------------------------------------------------
    // GET FRONT
    // --------------------------------------------------------
    void getFront()
    {
        if (front == NULL)
        {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Front: " << front->data << endl;
    }

    // --------------------------------------------------------
    // GET REAR
    // --------------------------------------------------------
    void getRear()
    {
        if (rear == NULL)
        {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Rear: " << rear->data << endl;
    }

    // --------------------------------------------------------
    // DISPLAY
    // --------------------------------------------------------
    void display()
    {
        if (front == NULL)
        {
            cout << "Deque is empty\n";
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
    // DEQUE USING ARRAY
    // ========================================================

    cout << "===== DEQUE USING ARRAY =====\n";

    int capacity;

    cout << "Enter deque size: ";
    cin >> capacity;

    DequeArray d1(capacity);

    d1.insertRear(20);
    d1.insertRear(30);

    d1.insertFront(10);
    d1.insertFront(5);

    cout << "Deque: ";
    d1.display();

    d1.getFront();
    d1.getRear();

    d1.deleteFront();

    cout << "After deleting from front: ";
    d1.display();

    d1.deleteRear();

    cout << "After deleting from rear: ";
    d1.display();


    // ========================================================
    // DEQUE USING LINKED LIST
    // ========================================================

    cout << "\n===== DEQUE USING LINKED LIST =====\n";

    DequeLL d2;

    d2.insertRear(20);
    d2.insertRear(30);

    d2.insertFront(10);
    d2.insertFront(5);

    cout << "Deque: ";
    d2.display();

    d2.getFront();
    d2.getRear();

    d2.deleteFront();

    cout << "After deleting from front: ";
    d2.display();

    d2.deleteRear();

    cout << "After deleting from rear: ";
    d2.display();


    return 0;
}