#include <iostream>
using namespace std;

class Node {
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
		Node* head = nullptr;
		Node* tail = nullptr;
		int length =0 ;
	public:
		LinkedList(){
		}
		LinkedList(int value){
			Node* newNode = new Node(value);
			head = tail = newNode;
			length = 1;
		}
		void printList(){
			Node* temp = head;
			int pos = 1;
			while(temp!= nullptr){
				cout << " At pos : " << pos << " , the value is " << temp->value <<endl;
				temp = temp->next;
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
			if(length == 0){
				head=tail=newNode;
				length = 1;
			}
			else{
				tail->next = newNode;
				tail = tail->next;
				length++;
			}
		}
		void prepend(int value){
			Node* newNode = new Node(value);
			if(length == 0){
				head = tail = newNode;
				length = 1;
			}
			else{
				newNode->next = head;
				head = newNode;
				length++;
			}
		}
		void deleteLast(){
			if(length == 0) return ;
			Node* temp = head;
			if(length == 1){
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
				tail->next = nullptr;
			}
			delete temp;
			length--;
		}
		void deleteFirst(){
			if(length == 0 ) return;
			Node* temp = head;
			if(length == 1 ){
				head = nullptr;
				tail = nullptr;
			}
			else{
				head = head->next;
			}
			delete temp;
			length--;
		}
		
		Node* get(int index){
			if(index<0 || index >= length ){ 
				return  nullptr ;
			}
			Node* temp = head;
			for(int i = 0; i < index;i++){
				temp = temp->next;
			}
			return temp;
		}
		/* 
		bool set(int index,int value){
			Node* temp = head;
			if(index <0 || index>=length) return false;
			for(int i = 0 ;i < index;i++){
				temp=temp->next;
			}
			temp->value = value;
			return true;
		}             // FUNCTION IS VALID BUT NOT OPTIMIZED.
		*/
		bool set( int index, int value){
			Node* temp = get(index);
			if(temp){
				temp->value = value;
				return true;
			}	
			else{
				return false;
			}
		}
		
		
		~LinkedList(){
			Node* temp = head;
			while(head){
				head=head->next;
				delete temp;
				temp = head;
			}
		}
};	

int main(){
	LinkedList* myLinkedList = new LinkedList(11);
	myLinkedList->append(3);
	myLinkedList->append(23);
	myLinkedList->append(7);
	
	myLinkedList->printList();
	cout << myLinkedList->set(1,4) <<endl;
	myLinkedList->printList();
}
