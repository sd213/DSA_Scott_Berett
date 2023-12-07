// mine complecated Code

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
			//cout << "########Creating Empty DoublyLinkedList ########"<<endl;
			head = nullptr;
			tail = nullptr;
			length = 0;
		}
		DoublyLinkedList(int value){
			//cout << "##### Creating DoublyLinkedList #####" << endl;
			Node* newNode = new Node(value);
			head = newNode;
			tail = newNode;
			length = 1;
		}
		void append(int value){
			//cout << "#### Appending Value: " << value << " to DoublyLinkedList ####"<< endl;
			Node* newNode = new Node(value);
			if(length == 0){
				head = newNode;
				tail = newNode;
			}
			else{
				tail->next = newNode;
				newNode->prev = tail;
				tail = newNode;
			}
			length++;
		}
		void prepend(int value){
			//cout << "#### Prepending Value: "<< value << " to DoublyLinkedList ####"<< endl;
			Node* newNode = new Node(value);
			if(length == 0){
				head = newNode;
				tail = newNode;
			}
			else{
				head->prev = newNode;
				newNode->next = head;
				head = newNode;
			}
			length++;
		}
		void delete_last(){
			if(length == 0 ) return ;
			Node* temp = tail;
			if (length == 1){
				head = nullptr;
				tail = nullptr;
			}
			else{
				tail = tail->prev;
				tail->next = nullptr;
			}
			delete temp;
			length --;
		}
		void delete_first(){
			if(length == 0 ) return;
			Node* temp = head;
			if(length == 1 ){
				head = nullptr;
				tail = nullptr;
			}
			else{
				head = head->next;
				head->prev = nullptr;
			}
			delete temp;
			length -- ;
		}
		Node* get(int index){
			if(index <0||index >= length) return nullptr;
			Node* temp = head;
			if(index<length/2){   // sir's method (optimized)
				for ( int i = 0 ;i < index ; i++){
					temp = temp->next;
				}
			}
			else{
				temp = tail;
				for(int i = length - 1; i > index; i--){
					temp = temp->prev;
				}
			}
			return temp;
			
		}
		bool set(int index,int value){
			Node* temp = get(index);
			if(temp){
				temp->value = value;
				return true;
			}
			return false;
		}
		bool insert(int index , int value){
			if(index < 0 || index>length) return false;
			Node* newNode = new Node(value);
			if(index == 0) {
				if(head == nullptr){
					head = newNode;
					tail = newNode;
					length = 1;
				}
				else{
					head->prev = newNode;
					newNode->next = head;
					head = newNode;
					length ++;
				}
				return true;
			}
			if(index == length){
				if(head == nullptr){
					head = newNode;
					tail = newNode;
					length = 1;
				}
				else{
					tail->next = newNode;
					newNode->prev = tail;
					tail  = newNode;
					length++;
				}
				return true;
			}
			else{
				Node* temp = head;
				
				if((index-1) < length / 2){  
					for ( int i = 0 ;i < (index-1); i++){
						temp = temp->next;
					}
				}
				else{
					temp = tail;
					for(int i = length - 1; i > (index-1); i--){
						temp = temp->prev;
					}
				}
				newNode->next = temp->next;
				newNode->prev = temp;
				temp->next = newNode;
				newNode->next->prev = newNode;
				length++;
				return true;
			}
			
			
		}
		void printList(){
			Node* temp = head;
			int pos = 1;
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
		
		
};
int main(){
	DoublyLinkedList* myDLL = new DoublyLinkedList(11);
	myDLL->append(3);
	myDLL->append(23);
	myDLL->append(7);
	cout << "#### Before Inseting the Node #### " << endl;
	myDLL->printList();
	
	myDLL->insert(2,4);
	cout << "#### After Inseting the Node at index 2 ####" << endl;
	myDLL->printList();
	
	return 0;
}
