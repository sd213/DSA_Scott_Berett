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

class Queue{
	private:
		Node* first;
		Node* last;
		int length;
	
	public:
		Queue(){
			first = nullptr;
			last = nullptr;
			length = 0;
		}
		Queue(int value){
			Node* newNode = new Node(value);
			first = newNode;
			last = newNode;
			length = 1;
		}
		void printQueue(){
			Node* temp = first;
			while(temp){
				cout << temp->value << endl;
				temp = temp -> next;
			}
		}
		void getFirst(){
			cout << " At First ( " << first << " )  Value is " << first->value << endl;
		}
		void getLast(){
			cout << " At Last ( " << last << " )  Value is " << last->value << endl;
		}
		void getLength(){
			cout << " Length of Queue : " << length << endl;
		}
};

int main(){
	Queue* myQueue = new Queue(7);
	cout << " Printing Queue : " << endl;
	myQueue->printQueue();
	
	myQueue->getFirst();
	myQueue->getLast();
	myQueue->getLength();
}
