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
			Node* newNode = new Node(value);
			head=tail=newNode;
			// it can be written as head = newNode ; tail = newNode;
			length=1;
		}
		void printList(){
			Node* temp = head;
			int pos = 1;
			while(temp) {
				cout << "At position "<< pos << " , value: " << temp->value <<endl;
				temp=temp->next;
				pos++;
			}
			
		}
		void getHead(){
			cout << "Head: " << head->value << endl;
		}
		void getTail(){
			cout << "Tail: " << tail->value << endl;
		}
		void getLength(){
			cout << "Length: " << length << endl;
		}
};
			
/* here instead of 
 * 	while(temp) {} 
 * 			we can write
 * 				while( temp != nullptr ){}
 */
   
 	
int main(){
	LinkedList* myLinkedList = new LinkedList(4);
	
	myLinkedList->getHead();
	myLinkedList->getTail();
	myLinkedList->getLength();
	
	myLinkedList->printList();
}
