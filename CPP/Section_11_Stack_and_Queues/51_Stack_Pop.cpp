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

class Stack{
	private:
		Node* top;
		int height;
	public:
		Stack(){
			cout << "#### Empty Stack Created ####" << endl;
			top = nullptr;
			height = 0;
		}
		Stack(int value){
			Node* newNode = new Node(value);
			top = newNode;
			height = 1;
		}
		
		void printStack(){
			Node* temp = top;
		
			while(temp){
				cout << temp->value << endl;
				temp = temp-> next;
				
			}
		}
		void push(int value){
			Node* newNode = new Node(value);
			newNode->next = top;
			top = newNode;
			height ++;
		}
		// pop is similar to delete first of linkedlist just like push is similar to prepend of linkedlist
		int pop(){
			//if(top == nullptr) return -1; // it was commented if the popped value is also -1 which will make us confused that if value of top was -1 or  stack is empty 
			if(top == nullptr) return INT_MIN;
			
			Node* temp = top;
			int popped_value = top->value;
			top = top ->next;
				
			delete temp;
			height --;
			return popped_value;
		
		}
		void getTop(){
			cout << " Stack's Top ( " << top <<" ) and it's Value : " << top->value << endl;
		}
		void getHeight(){
			cout << " Height of Stack : " << height << endl;
		}
		~Stack(){
			Node* temp = top;
			while(top){
				top = top->next;
				delete temp;
				temp = top;
			}
		}
};
int main(){
	Stack* myStack = new Stack(4);
	myStack->push(5);
	myStack->push(6);
	myStack->push(7);
	myStack->push(8);
	
	
	cout << " BEFORE POPPING : " << endl;
	myStack->getTop();
	myStack->getHeight();
	cout << endl;
	cout << "#### printing Stack Before Popping ####" << endl;
	myStack->printStack();
	

	cout << endl << endl;
	cout << " Popped Value : " << myStack->pop();
	cout << endl << endl;
	
	
	cout << " AFTER POPPING : " << endl;
	myStack->getTop();
	myStack->getHeight();
	cout << endl;
	cout << "#### printing Stack After Popping ####" << endl;
	myStack->printStack();
	
	
}
