#include<bits/stdc++.h>
using namespace std;

class MyCircularDeque {
    vector<int> arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    MyCircularDeque(int k) {
        arr.resize(k);
        front = 0;
        rear = -1;
        capacity = k;
        size = 0;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        if(isEmpty()){
            front = 0;
            rear = 0;
        }
        else{
            front = (front - 1 + capacity) % capacity;
        }
        arr[front] = value;
        size++;

        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        if (isEmpty()){
            front = 0;
            rear = 0;
        }
        else{
            rear = (rear + 1) % capacity;
        }
        arr[rear] = value;
        size++;

        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        size--;
        if(size == 0){
            rear = 0;
            front = -1;
        }else{
            front = (front + 1) % capacity;
        }
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        size--;
        if(size==0){
            front = -1;
            rear = 0;
        }
        else{
            rear = (rear - 1 + capacity) % capacity;
        }
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return arr[front];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        if (size == 0) return true;
        return false;
    }
    
    bool isFull() {
        if (size == capacity) return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
 
int main(){
    
    return 0;
}