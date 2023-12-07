#include <iostream>
using namespace std;

class Node{
	public:
		int value;
		Node* next;
		
		Node(int value){
			this->value = value;
			next = nullptr;
		}
};

class LinkedList{
	private:
		Node* head;
		Node* tail;
		int length;
		
	public:
		LinkedList(int value){
			Node* newNode= new Node(value);
			head = tail = newNode;
			length = 1;
		}
		void printList(){
			Node* temp = head;
			int pos = 1;
			while(temp){
				cout << "At pos: " << pos<< " , value is "<<temp->value << endl;
				temp=temp->next;
				pos++;			
			}
		}
		void getHead(){
			cout << " head( "<< head <<" ) value is "<< head->value << endl;
		}
		void getTail(){
			cout << " tail( "<< tail <<" ) value is "<< tail->value << endl;
		}
		void getLength(){
			cout << " LinkedList  Length is " << length<< endl;
		}
		~LinkedList(){
			Node* temp = head;
			while(head){
				head = head->next;
				delete temp;
				temp = head;
			}
			length = 0;
		}

};
int main(){
	LinkedList* myLinkedList = new LinkedList(33);
	myLinkedList-> getHead();
	myLinkedList-> getTail();
	myLinkedList-> getLength();
	myLinkedList-> printList();
	
	delete myLinkedList;
	cout<< "After Deleting" << endl;
	myLinkedList-> printList(); // print segmentation fault
	
}
