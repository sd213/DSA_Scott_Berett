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
class LinkedList{
	private:
		Node* head;
		Node* tail;
		int length;
	public:
	LinkedList(){
		head = nullptr;
		tail = nullptr;
		length = 0;
		cout << " Empty LinkedList Created: " << endl;
	}
	LinkedList(int value){
		Node* newNode = new Node(value);
		head = newNode;
		tail = newNode;
		length = 1;
		cout << " LinkedList created: " << endl;
	}
	void append(int value){
		Node* newNode = new Node(value);
		if(head==nullptr){
			head = newNode;
			tail = newNode;
			length = 1;
		}
		else{
			tail->next = newNode;
			tail = newNode;
			length++;
		}
	}
	void prepend(int value){
		Node* newNode = new Node(value);
		if(head == nullptr){
			head = newNode;
			tail = newNode;
			length = 1;
		}
		else{
			newNode->next = head;
			head = newNode;
			length ++;
		}
	}
	void delete_last(){
		Node* temp = head;
		if(head == nullptr) return;
		
		else if(length == 1){
			head = nullptr;
			tail = nullptr;
		}
		else{
			Node* pre = head;
			while(pre->next->next){
				pre=pre->next;
			}
			temp = pre->next;
			tail = pre;
			tail->next = nullptr;
		}
		delete temp;
		length --;
 	}
 	void delete_first(){
		Node* temp = head;
		if(head == nullptr) return ;
		else if(length == 1){
			head = nullptr;
			tail = nullptr;
		}
		else{
			head = head->next;
		}
		delete temp;
		length --;
	}
	Node* get(int index){
		if(index < 0 || index >= length) return nullptr;
		else{
			Node* temp = head;
			for(int i=0;i<index;i++){
				temp = temp->next;
			}
			return temp;
		}
	}
	bool set(int index,int value){
		Node* temp = get(index);
		if(temp){
			temp->value = value;
			return true;
		}
		else{
			return false;
		}
	}

	bool insert(int index,int value){
		if(index<0 || index>length) return false;
		if(index == 0){ prepend(value); return true;}
		if(index == length){append(value); return false;}
		Node* temp = get(index-1);
		Node* newNode = new Node(value);
		newNode->next = temp ->next;
		temp->next = newNode;
		length ++;
	}
	bool delete_Node(int index){
		if( index< 0 || index >= length) return false;
		if(index == 0) {delete_first(); return true;}
		if(index == length ){ delete_last(); return true;}
		Node* pre = get(index-1);
		Node* temp = pre->next;
		pre->next = temp->next;
		
		delete  temp;
		length --;
		return true;
	}
	void reverse(){
		Node* before = nullptr;
		
		Node* temp = head;
		Node* after = head;
		head = tail ;
		tail = temp;
		
		
		
		/*
		
		int i = 0;
		while(i<length){
			after = after->next;
			temp->next = before;
			before=temp;
			temp = after;
			i++;
		}
		*/
		while(temp){
			after = after->next;
			temp->next = before;
			before = temp;
			temp = after;
		}
	}
	void PrintList(){
		Node* temp = head;
		int pos = 1;
		while(temp){
			cout << "At pos : "<< pos << " The value is "<< temp->value << endl;
			temp = temp->next;
			pos++;
		}
	}
	void getHead(){
		cout<< " The head ( "<<head<<" ) value is "<< head->value<<endl;
	}
	void getTail(){
		cout<< " The tail ( "<< tail<< " ) value is " << tail->value << endl;
	}
	void getLength(){
		cout<< " The Length of LinkedList is "<< length << endl;
	}
	~LinkedList(){
		Node* temp = head;
		while(head!=nullptr){
			head = head->next;
			delete temp;
			temp = head;
		}
		cout << "LinkedList Deleted " << endl;
	}
};
int main(){
	cout << " Hello World " << endl;
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
	myLinkedList1->PrintList();
	
	myLinkedList1->reverse();
	cout << " LL after Reverse : " << endl;
	myLinkedList1->PrintList();
	

}
