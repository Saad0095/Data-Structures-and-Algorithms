#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int val){
            data = val;
            next = NULL;
        }
};

class Stack{
    private:
        Node* top;
    
    public:
        Stack(): top(NULL){}

        void push(int val){
            Node* newNode = new Node(val);
            if(top == NULL){
                top = newNode;
            }
            else{
                newNode -> next = top; 
                top = newNode; 
            }
        }

        void pop(){
            if (top == NULL){
                cout << "Stack is empty" << endl;
                return;
            }

            Node* temp = top;
            top = top -> next;
            temp->next = NULL;
            delete temp;
        }

        int peek(){
            if (top == NULL){
                cout << "Stack is empty" << endl;
                return -1;
            }

            return top->data;
        }

        void display(){
            Node* temp = top;

            while(temp != NULL){
                cout << "-> " << temp->data;
                temp = temp -> next;
            }
            cout << endl; 
        }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    cout << "Top: " << s.peek() << endl;

    s.pop();

    s.display();

    return 0;
}