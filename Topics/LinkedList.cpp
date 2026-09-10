#include<bits/stdc++.h>
using namespace std;

class Node{
    private:
        int data;
        Node* next;

    public:
        Node(int d){
            data = d;
            next = NULL;
        }
};

class List{
    private:
        Node* head;
        Node* tail;

    public:
        List(){
            head = tail = NULL;
        }
};

int main(){
    
    return 0;
}