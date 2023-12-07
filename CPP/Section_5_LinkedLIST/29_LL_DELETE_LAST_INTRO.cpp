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
			int pos = 1;
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
			if(head == nullptr){  // here for testing we can substitute 'head == nullptr' with 'length == 0' or 'tail == nullptr' to check the linkedlist empty or not.
				head=tail=newNode;
				length=1;
			}
			else{
				tail->next=newNode;
				tail = tail->next;
				length++;
			}
		}
		
		void deleteLast(){
			/* // my own method
			if(head == nullptr){
				cout << " Nothing to Delete" << endl;
			}
			else if ( head == tail){
				Node* temp = head;
				delete temp;
				head = tail = nullptr;
				length = 0;
			}
			else{
				Node *temp = head;
				while(temp->next->next != nullptr){
					temp=temp->next;
				}
				tail=temp;
				temp = temp-> next;
				delete temp;
				tail->next = nullptr;
				length --;				
			
			}
			*/
			Node* temp = head;
			if(temp == nullptr){
				cout << " Nothing to delete " << endl;
			}
			else if ( head == tail){
				delete temp;
				head = tail = nullptr;
				length = 0;
			}
			else {
				Node* pre = nullptr;
				while(temp->next != nullptr){
					pre = temp;
					temp = temp->next;
					
				}
				delete temp;
				tail = pre;
				tail->next = nullptr;
				length --;
			}
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
	LinkedList* myLinkedList = new LinkedList(443);
	
	myLinkedList->append(34);
	myLinkedList->append(23);
	myLinkedList->append(898);
	cout << " Afte Appending : " << endl;
	myLinkedList->getHead();
	myLinkedList->getTail();
	myLinkedList->getLength();
	cout << " Printing LinkedList1 " << endl;
	myLinkedList->printList();
	LinkedList* myLinkedList2 = new LinkedList();
	myLinkedList2->append(23423);
	myLinkedList2->append(89809);
	myLinkedList2->append(423);
	cout << " Afte Appending : " << endl;
	myLinkedList2->getHead();
	myLinkedList2->getTail();
	myLinkedList2->getLength();
	cout << " Printing LinkedList2 " << endl;
	myLinkedList2->printList();
	cout << " Deleting Last element of LinkedList2 " << endl;
	myLinkedList2->deleteLast();
	cout << " After Deleting Last element  of second LinkedList" << endl;
	myLinkedList2->printList();
	cout << " Deleting Last element of LinkedList2 " << endl;
	myLinkedList2->deleteLast();
	cout << " After Deleting Last element  of second LinkedList" << endl;
	myLinkedList2->printList();
	
	cout << " Creating Empty LinkedList" << endl;
	LinkedList* myLinkedList3 = new LinkedList();
	cout << " Deleting Last element of third LinkedList" << endl;
	myLinkedList3->deleteLast();
	
	cout << " Creating Single LinkedList " << endl;
	LinkedList* myLinkedList4 = new LinkedList(465);
	cout << " Printing Single LinkedList : " << endl;
	myLinkedList4->printList();
	
	cout << " deleting Last element of LinkedList 4 " << endl;
	myLinkedList4->deleteLast();
	cout << " Printing LinkedList4 : " << endl;
	myLinkedList4->printList();
	
	cout << "GOOD BYE" << endl;
}
