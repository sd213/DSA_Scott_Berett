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
		//Node* bottom;
		int height;
	public:
		Stack(int value){
			Node* newNode = new Node(value);
			top = newNode;
			height = 1;
		}
		
		
		void printStack(){
			Node* temp = top;
			while(temp){
				cout<< temp->value << endl;
				temp = temp-> next;
				
			}
		}
		void getTop(){
			cout << " Stack's Top ( " << top <<" ) and it's Value : " << top->value << endl;
		}
		void getHeight(){
			cout << " Height of Stack : " << height << endl;
		}
};

int main(){
	Stack* myStack = new Stack(4);
	
	myStack->getTop();
	myStack->getHeight();
	cout << "#### printing Stack ####" << endl;
	myStack->printStack();
	
	
}
