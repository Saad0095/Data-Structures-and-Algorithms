#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(NULL) {};
};

class CircularList
{
    Node *head;
    Node *tail;

public:
    CircularList(){
        head = tail = NULL;
    }

    void insertAtHead(int val){
        Node* newNode = new Node(val);
        if (head == NULL){
            head = tail =  newNode;
            tail -> next = head;
        }
        else{
            // newNode->next = head;
            // head = newNode;
            // tail->next = head;

            // Using Tail Pointer Only (Without head pointer)
            newNode-> next = tail -> next;
            tail->next = newNode;
            head = tail->next; // if need to update head, otherwise, head will stay same (eg 5)
        }
    }

    void insertAtTail(int val){
        Node* newNode = new Node(val);
        if (head == NULL){
            head = tail = newNode;
            tail->next = head;
        }
        else{
            // newNode->next = head;
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteAtHead(){
        if (head == NULL){
            return;
        }else if( head == tail){
            delete head;
            head = tail = NULL;
        }
        else{
            Node* temp = head;
            head = head -> next;
            tail -> next = head;

            temp->next = NULL;
            delete temp;
        }
    }

    void deleteAtTail(){
        if (head == NULL) return;
        else if (head == tail){
            delete head;
            head = tail = NULL;
        }
        else{
            Node* temp = head;

            while(temp->next != tail){
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail -> next = head;
        }
    }
    void printLL(){
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        }while(temp != head);

        cout << head -> data << endl;
    }
};

int main()
{
    CircularList cll;
    cll.insertAtHead(5);
    cll.insertAtHead(12);
    cll.insertAtHead(17);
    cll.printLL();
    
    cll.insertAtTail(18);
    cll.printLL();

    cll.deleteAtHead();
    cll.printLL();
    
    cll.deleteAtTail();
    cll.printLL();
    return 0;
}