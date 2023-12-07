#include <iostream>

using namespace std;

class Node{
	public:
		int value;
		Node* prev;
		Node* next;
		
		Node(int value){
			this->value = value;
			prev = nullptr;
			next = nullptr;
		}
};
class DoublyLinkedList{
	private:
		Node* head = nullptr;
		Node* tail = nullptr;
		int length = 0;
	
	public:
		DoublyLinkedList(){
			cout << "########Creating Empty DoublyLinkedList ########"<<endl;
			head = nullptr;
			tail = nullptr;
			length = 0;
		}
		DoublyLinkedList(int value){
			cout << "##### Creating DoublyLinkedList #####" << endl;
			Node* newNode = new Node(value);
			head = newNode;
			tail = newNode;
			length = 1;
		}
		void append(int value){
			cout << "#### Appending Value: " << value << " to DoublyLinkedList ####"<<endl;
			Node* newNode = new Node(value);
			if(length == 0){
				head = newNode;
				tail = newNode;
			}
			else{
				tail->next = newNode;
				newNode->prev = tail;
				tail = newNode;
			}
			length++;
		}
		
		void printList(){
			Node* temp = head;
			int pos = 1;
			while(temp != nullptr){
				cout << " At Pos( " << pos<<" ) value is "<< temp->value<< endl;
				temp = temp -> next;
				pos ++;
			}
		}
		void getHead(){
			cout << "At Head( " << head << " ) value is " << head->value << endl;
		}
		void getTail(){
			cout << "At Tail( " << tail << " ) value is " << tail->value << endl;
		}
		void getLength(){
			cout << "Length: " << length << endl;
		}
		
		
};

int main(){
	
	DoublyLinkedList* myDLL = new DoublyLinkedList(1);
	
	cout << "####Before Appending####" << endl;
	myDLL-> printList();
	myDLL->append(2);
	cout << "####After Appending####" << endl;
	myDLL->printList();
	return 0;
}
