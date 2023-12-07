#include<iostream>
using namespace std;

class Node{
	public:
		int value;
		Node* next;
		
		Node(int value){
			this->value = value;
			this->next = nullptr;
		} 
		/*
		 *  Above statement can also be written as 
		 * 	Node(int val){
		 * 		value = value;
		 * 		next = nullptr;
		 * }
		 * 
		*/
};

class LinkedList{
	private:
		Node* head;
		Node* tail;
		int length;
	
	public:
		LinkedList(int value){
			Node* newNode = new Node(value);
			head = newNode;
			tail = newNode;
			length = 1;
		}
};

int main(){
	LinkedList* myLinkedList = new LinkedList(4);
	cout << "Hess" << endl;
	return 0;
}

