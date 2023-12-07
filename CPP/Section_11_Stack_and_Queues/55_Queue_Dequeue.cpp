#include <iostream>
#include <climits>
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
		void enqueue( int value ){
			Node* newNode = new Node(value);
			if(length == 0){
				first = newNode;
				last = newNode;
			}
			else{
				last->next = newNode;
				last = newNode;
				
			}
			length ++;
		}
		int dequeue (){
			if(length == 0) return INT_MIN;
			Node* temp = first;
			int dequeue_value = temp->value;
			if(length == 1){
				first = nullptr;
				last = nullptr;
			}
			else{
				first = first->next;
				
			}
			delete temp;
			length --;
			return dequeue_value;
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
		~Queue() {
            Node* temp = first;
            while (first) {
                first = first->next;
                delete temp;
                temp = first;
            }
        }
};


int main(){
	Queue* myQueue = new Queue(7);
	myQueue->enqueue(8);
	myQueue->enqueue(9);
	myQueue->enqueue(10);
	
	cout << " Printing Queue  Before deQueue: " << endl;
	myQueue->printQueue();
	cout << endl << endl;

	cout << " Popped value : " << myQueue->dequeue() << endl;
	cout << " Printing Queue  After  1st deQueue: " << endl;
	myQueue->printQueue();
	cout << endl << endl;
	
	cout << " Popped value : " << myQueue->dequeue() << endl;
	cout << " Printing Queue  After  2nd deQueue: " << endl;
	myQueue->printQueue();
	cout << endl << endl;
	
	cout << " Popped value : " << myQueue->dequeue() << endl;
	cout << " Printing Queue  After  3rd deQueue: " << endl;
	myQueue->printQueue();
	cout << endl << endl;

	cout << " Popped value : " << myQueue->dequeue() << endl;
	cout << " Printing Queue  After  4th deQueue: " << endl;
	myQueue->printQueue();
	cout << endl << endl;
	
	cout << " Popped value : " << myQueue->dequeue() << endl;
	cout << " Printing Queue  After  5th deQueue: " << endl;
	myQueue->printQueue();
	cout << endl << endl;
}
