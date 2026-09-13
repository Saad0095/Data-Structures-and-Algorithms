// Linked List

#include<bits/stdc++.h>
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

class List{
	public:
		Node* head;
		Node* tail;

		List(){
			head = tail = NULL;
		}
		
		void push_front(int val){ // O(1)
			Node* newNode = new Node(val);
			if(head == NULL){
				head = tail = newNode;
			}else{
				newNode -> next = head;
				head = newNode;
			}
		}
		
		void push_back(int val){ // O(1)
			Node* newNode = new Node(val);
			if(tail == NULL){
				head = tail = newNode;
			}
			else{
				tail -> next = newNode;
				tail = newNode;
			}
		}
		
		void pop_front(){ // O(1)
			if(head == NULL){
				cout << "Linked List is empty!" << endl; 
				return;
			}
			Node* temp = head;
			head = head-> next;
			delete temp;
		}
		
		void pop_back(){  // O(n)
			if(tail == NULL){
				cout << "Linked List is empty!" << endl; 
				return;
			}
			
			Node* temp = head;
			while(temp -> next != tail){
				temp = temp -> next;
			}
			
			temp->next = NULL;
			delete tail;
			tail = temp;
		}
		
		void insert(int val, int pos){ // O(n)
			if(pos < 0){
				cout << "Invalid position" << endl;
				return;
			}
			if(pos == 0){
				push_front(val);
				return;
			}
			Node* temp = head;
			for(int i=0; i < pos-1; i++){
				if(temp == NULL){
				cout << "Invalid position" << endl;
				return;
				}
				temp = temp -> next;
			}
			
			Node* newNode = new Node(val);
			newNode->next = temp -> next;
			temp->next = newNode;
		}
		
		void deleteNode(int val){ // O(n)
			Node* temp = head;
			Node* prev = NULL;
			
			if(temp!= NULL && temp->data == val){
				pop_front();
				return;
			}
			
			while(temp!= NULL && temp->data !=val){
				prev = temp;
				temp = temp-> next;
			}
			if(temp == NULL){
				cout << "Data nt found!" << endl;
				return;
			}
			prev->next = temp->next;
			delete temp;
		}
		
		int search(int val){ // O(n)
			Node* temp = head;
			int index = 0;
			while(temp!= NULL){
				if(temp->data == val){
					return index;
				}
				temp = temp->next;
				index++;
			}
			return -1;
		}
			            
		void printll(){ // O(n)
			Node* temp = head;
			while(temp != NULL){
				cout << " -> " << temp -> data;
				temp = temp -> next;
			}
            cout << "NULL" << endl;
		}
};

int main(){
	List myList;
	
	myList.push_back(4);
	myList.push_back(6);
	myList.push_back(8);
	myList.push_front(18);
	myList.push_front(48);
	myList.push_front(4238);
	
	myList.printll();
	
	myList.pop_front();
	myList.printll();
	
	myList.pop_back();
	myList.printll();
	
	myList.insert(12,0);
	myList.printll();
	
	myList.insert(53, 2);
	myList.printll();
	myList.deleteNode(18);
	myList.printll();
	
	int val;
	cout << "Enter Value to find: "; 
	cin >> val;
	cout<< "Index of " << val << " is "<< myList.search(val) << endl;
	return 0;
}