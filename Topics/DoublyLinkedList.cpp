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

        void pop_front(){
             if(head == NULL){
                cout<< "LL is empty" << endl;
                return;
            }
            Node* temp = head;
            head = head->next;

            if (head != NULL){
                head->prev = NULL;
            }

            temp -> next = NULL;
            delete temp;
        }

        void pop_back(){
            if( tail == NULL){
                cout<< "LL is empty" << endl;
                return;
            }

            Node* temp = tail;
            tail = tail-> prev;
            
            if (tail != NULL){
                tail-> next = NULL;
            }
            
            temp -> prev = NULL;
            delete temp;
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

    dll.push_back(9);
    dll.printLL();
    
    dll.pop_front();
    dll.printLL();
    
    dll.pop_back();
    dll.printLL();

    return 0;
}