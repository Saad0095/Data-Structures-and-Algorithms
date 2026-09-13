#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int val){
            data = val;
            next = prev = NULL;
        }
};

class DoublyList{
    public:
        Node* head;
        Node* tail;

        DoublyList(){
            head = tail = NULL;
        }

        void push_front(int val){
            Node* newNode = new Node(val);
            if(head == NULL){
                head = tail = newNode;
            }
            else{
                newNode -> next = head;
                head -> prev = newNode;
                newNode->prev = NULL;
                head = newNode;
            }
        }
        void push_back(int val){
            Node* newNode = new Node(val);
            if(head == NULL){
                head = tail = newNode;
            }
            else{
                // newNode->next = NULL;
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
        }

        void printLL(){
            Node* temp = head;
            while(temp != NULL){
                cout << temp->data << " <=> "; // Double <=>
                temp = temp ->next;
            }
            cout << "NULL" << endl;
        }
};

int main(){
    DoublyList dll;
    dll.push_front(3);
    dll.push_front(5);

    dll.printLL();
    return 0;
}