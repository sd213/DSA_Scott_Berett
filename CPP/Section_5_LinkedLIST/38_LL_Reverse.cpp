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

	bool insert ( int index, int value){
		if ( index < 0 || index > length) return false;
		if (index == 0){
			prepend(value);
			return true;
		}
		if (index == length){
			append(value);
			return true;
		}
		Node* newNode = new Node(value);
		Node* temp = get(index-1);
		newNode->next = temp -> next;
		temp->next = newNode;
		length++;
		return true;
	}
	void deleteNode( int index){
		if(index < 0 || index >= length) return ;
		if(index == 0) return deleteFirst();
		if(index == length) return deleteLast();
		Node* pre = get(index -1 );
		Node* temp = pre->next;
		pre->next = temp->next;
		temp->next = nullptr;
		delete temp;
		length--;
	}
	void reverse(){
		/* 
		Node* temp = head; // my version code
		head = tail;
		tail = temp;
		Node* after = temp->next;
		Node* before = nullptr;
		
		for(int i = 0 ; i < length ; i++){
			temp->next = before;
			before = temp;
			temp = after;
			if(after){
				after = after -> next;
			}
			else{
				break;
			}
				
		}
		*/
		Node* temp = head;
		head = tail;
		tail = temp;
		Node* after = nullptr;
		Node* before = nullptr;
		
		for(int i = 0; i < length ; i++){
			after = temp -> next;
			temp->next = before;
			before = temp;
			temp = after;
		}
		
		
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
	LinkedList* myLinkedList1 = new LinkedList(1);
	myLinkedList1->append(2);
	myLinkedList1->append(3);
	myLinkedList1->append(4);
	myLinkedList1->append(5);
	myLinkedList1->append(6);
	myLinkedList1->append(7);
	myLinkedList1->append(8);
	myLinkedList1->append(9);
	myLinkedList1->append(10);
	myLinkedList1->append(11);
	myLinkedList1->append(12);
	myLinkedList1->append(13);
	myLinkedList1->append(14);
	
	cout << " LL before Reverse : " << endl;
	myLinkedList1->printList();
	
	myLinkedList1->reverse();
	cout << " LL after Reverse : " << endl;
	myLinkedList1->printList();
	
	
}
