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
		LinkedList(){
			head = tail = nullptr;
			length = 0;
		}
		LinkedList(int value){
			Node* newNode= new Node(value);
			head = tail = newNode;
			length = 1;
		}
		void printList(){
			Node* temp = head;
			int pos= 1;
			while(temp){
				cout << "At pos: " << pos << " , value is "<<temp->value << endl;
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
		
		void append(int value){
			Node* newNode = new Node(value);
			if(head == nullptr){  
				head=tail=newNode;
				length=1;
			}
			else{
				tail->next=newNode;
				tail = tail->next;
				length++;
			}
		}
		
		void prepend(int value){
			Node* newNode = new Node(value);
			if(head == nullptr){ // or length == 0 or tail == nullptr
				head = newNode;
				tail = newNode;
				length = 1;
			}
			else{
				newNode->next=head;
				head = newNode;
				length ++;
			}
		}
		
		void deleteLast(){
			// optimized sir method
			if(length == 0) return ;
			Node* temp = head;
			if( length == 1 ){
				head = nullptr;
				tail = nullptr;
			}
			else{
			Node* pre = head;
			while(temp->next){
				pre = temp;
				temp = temp -> next;
			}
			tail = pre;
			tail -> next = nullptr;
			
			
			}
			delete temp;
			length--;
		}
		
		~LinkedList(){
			Node* temp = head;
			while(head != nullptr){
				head = head->next;
				delete temp;
				temp = head;
			}
		}
};

int main(){
	LinkedList* myLinkedList1 = new LinkedList(443);
	LinkedList* myLinkedList2 = new LinkedList();
	
	cout << "Printing 1st LinkedList: " << endl;
	myLinkedList1->printList();
	cout << "Appending 1st LinkedList" << endl;
	myLinkedList1->append(23);
	cout << "Printing 1st LinkedList: " << endl;
	myLinkedList1->printList();
	cout << "Appending 1st LinkedList again" << endl;
	myLinkedList1->append(534);
	cout << "Printing 1st LinkedList: " << endl;
	myLinkedList1->printList();
	cout << "prepending 1st LinkedList " << endl;
	myLinkedList1->prepend(442);
	cout << "Printing 1st LinkedList: " << endl;
	myLinkedList1->printList();
	cout << "prepending 1st LinkedList again" << endl;
	myLinkedList1->prepend(441);
	cout << "Printing 1st LinkedList: " << endl;
	myLinkedList1->printList();
	cout << "Deleting Last of 1stLinkedList " << endl;
	myLinkedList1->deleteLast();
	cout << "Printing 1st LinkedList: " << endl;
	myLinkedList1->printList();
	cout << endl << endl;
	 
	cout << " 2nd LinkedList: " << endl;
	cout << "Printing 2nd LinkedList: " << endl;
	myLinkedList2->printList();
	cout << "Appending 2nd LinkedList" << endl;
	myLinkedList2->append(4);
	cout << "Printing 2nd LinkedList: " << endl;
	myLinkedList2->printList();
	cout << "Appending 2nd LinkedList again" << endl;
	myLinkedList2->append(5);
	cout << "Printing 2nd LinkedList: " << endl;
	myLinkedList2->printList();
	cout << "prepending 2nd LinkedList " << endl;
	myLinkedList2->prepend(3);
	cout << "Printing 2nd LinkedList: " << endl;
	myLinkedList2->printList();
	cout << "prepending 2nd LinkedList again" << endl;
	myLinkedList2->prepend(2);
	cout << "Printing 2nd LinkedList: " << endl;
	myLinkedList2->printList();
	cout << "prepending 2nd LinkedList again" << endl;
	myLinkedList2->prepend(1);
	cout << "Printing 2nd LinkedList: " << endl;
	myLinkedList2->printList();
	cout << "Deleting Last of 2nd LinkedList " << endl;
	myLinkedList2->deleteLast();
	cout << "Printing 2nd LinkedList: " << endl;
	myLinkedList2->printList();
	cout << "Deleting Last of 2nd LinkedList " << endl;
	myLinkedList2->deleteLast();
	cout << "Printing 2nd LinkedList: " << endl;
	myLinkedList2->printList();
	cout << "Deleting Last of 2nd LinkedList " << endl;
	myLinkedList2->deleteLast();
	cout << "Printing 2nd LinkedList: " << endl;
	myLinkedList2->printList();
	
	cout << "GOOD BYE" << endl;
}
