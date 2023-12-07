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
		// here we borrrow prepend function of linked list as workings are same.
		void push(int value){
			cout << "pushing the value " << value << " to stack"<<endl;
			Node* newNode = new Node(value);
			/* here we don't need if condition like prepend function of linkedlist as linkedlist has extra pointer that is tail and we don't have tail or equivalent to tail here
			
			if(top == nullptr){ // we can substitute 'height == 0' with 'top == nullptr'
				top = newNode;
				height = 1;
			}
			
			else{
				newNode->next = top;
				top = newNode;
				height++;
			}
			*/
			newNode->next = top;
			top = newNode;
			height ++;
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
	
	cout << " BEFORE PUSHING : " << endl;
	myStack->getTop();
	myStack->getHeight();
	cout << endl;
	cout << "#### printing Stack Before Pushing ####" << endl;
	myStack->printStack();
	
	myStack->push(5);
	myStack->push(6);
	myStack->push(7);
	myStack->push(8);
	
	cout << endl << endl;
	
	cout << " AFTER PUSHING : " << endl;
	myStack->getTop();
	myStack->getHeight();
	cout << endl;
	cout << "#### printing Stack After Pushing ####" << endl;
	myStack->printStack();
	
}
