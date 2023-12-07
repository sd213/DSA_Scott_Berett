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
		
		void printList(){
			Node* temp = head;
			int pos = 1;
			cout << "####Printing DoublyLinkedList####" << endl;
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
		
		~DoublyLinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }
		
};

int main(){
	
	DoublyLinkedList* myDLL = new DoublyLinkedList(7);
	
	myDLL-> printList();
	return 0;
}
