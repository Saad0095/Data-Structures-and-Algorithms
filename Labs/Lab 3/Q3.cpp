#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList
{
public:
    Node *head;
    Node *tail;

    DoublyList()
    {
        head = tail = NULL;
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            // newNode->next = NULL;
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void concat(DoublyList& other){
        if(other.head == nullptr){
            return ;
        }
        if(head ==NULL){
            head = other.head;
            tail = other.tail;
        }
        else{
            tail->next = other.head;
            other.head->prev = tail;
            tail = other.tail;
        }
    }
   
    void printLL()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " <=> "; // Double <=>
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    DoublyList L, M, N;
    for (int i = 1; i <= 10; i++){
        if (i % 2 == 0){
            L.push_back(i);
        }
        else{
            M.push_back(i);
        }
    }
    cout << "DLL L: " << endl;
    L.printLL();
    cout << "DLL M: " << endl;
    M.printLL();
    N.concat(L);
    N.concat(M);
    cout << "DLL N: " << endl;
    N.printLL();
    return 0;
}