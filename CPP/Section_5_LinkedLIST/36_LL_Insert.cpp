#include <iostream>
using namespace std;

class Node{
	public:
		int value;
		Node* next;
		
		Node(int value){
			this->value = value;
			this->next = nullptr;
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
			Node* newNode = new Node(value);
			head=tail=newNode;
			length = 1;
		}
		void printList(){
			Node* temp = head;
			int pos = 1;
			while(temp){
				cout << " At pos: " << pos << " the value is : "<<temp->value<<endl;
				temp=temp->next;
				pos++;
			}
		}
		void getHead(){
			cout << " value of head( "<<head<<" ) is : " << head->value << endl;
		}
		void getTail(){
			cout << " value of tail( " << tail << " ) is : " << tail->value <<endl;
		}
		void getLength(){
			cout << " Length of LinkedList : " << length << endl;
		}
		void append(int value){
			cout << " Appending Value " << value << " to the end of LinkedList" << endl;
			Node* newNode = new Node(value);
			if(head == nullptr){
				head = tail = newNode;
				length = 1;
			}
			else{
				tail->next = newNode;
				tail = newNode;
				length++;
			}
		}
		void prepend(int value){
			cout << " prepending Value " << value << " to start of LinkedList " << endl;
			Node* newNode = new Node(value);
			if(head == nullptr){
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
			if ( length == 0 ) {
				cout<< "Nothing here to Delete" <<endl;
				return;
			}
			Node* temp = head;
			if( length == 1){
				head = nullptr;
				tail = nullptr;
			}
			else{
				Node* pre = head;
				while(temp->next){
					pre = temp;
					temp = temp->next;
				}
				tail = pre;
				tail->next = nullptr;
			}
			delete temp;
			length --;
		}
		void deleteFirst(){
			if( head == nullptr){
				cout << " Nothing here to delete " << endl;
				return;
			}
			Node* temp = head;
			if( length == 1){
				head = nullptr;
				tail = nullptr;
			}
			else{
				head = head->next;
				temp -> next = nullptr;
			}
			delete temp;
			length --;
		}
		Node* get( int index ){
			if ( index < 0 || index >= length) return nullptr;
			else{
				Node* temp = head;
				for(int i = 0 ; i < index ; i++){
					temp = temp->next;
				}
				return temp;
			}
		}
		bool set( int index , int value ){
			Node* temp = get(index);
			if( temp ){
				temp->value = value;
				return true;
			}
			else {
				return false;
			}
		}
	bool insert(int index, int value){
	
		if( index < 0 || index > length ) return false;
		if( index == 0 ) {
			//Node* newNode = new Node(value);
			//newNode->next = head;
			//head = newNode;
			//length++;
			prepend(value);
			return true;
		}
		if( index == length){
			
			//Node* newNode = new Node(value);
			//tail->next = newNode;
			//tail = newNode;
			//length++;
			append(value);
			return true;
		}
		Node* newNode = new Node(value);
		Node* temp = get(index-1);
		newNode->next = temp->next;
		temp->next = newNode;
		length++;
		return true;
	}


	~LinkedList(){
		cout << " Destroying LinkedList " << endl;
		Node* temp = head;
		while(head){
			head=head->next;
			delete temp;
			temp=head;
		}
	}
};

int main(){
	LinkedList* myLinkedList1 = new LinkedList(33);
	myLinkedList1->append(35);
	myLinkedList1->printList();
	cout << endl <<endl;
	myLinkedList1->insert(1,34);
	myLinkedList1->printList();
	cout << endl <<endl;
	myLinkedList1->insert(0,32); 
	myLinkedList1->printList();
	cout << endl <<endl;
	myLinkedList1->insert(4,36);
	myLinkedList1->printList();
}
