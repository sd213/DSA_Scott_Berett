#include <iostream>
using namespace std;

class Node{
	public:
		string key;
		int value;
		Node* next;
		Node(string key , int value){
			this->key = key;
			this->value = value;
			next = nullptr;
		}
};
class HashTable{
	private:
		static int const SIZE = 7;
		Node* dataMap[SIZE];
	public:
		HashTable(){
			for(int i = 0 ; i < SIZE ; i++){
				dataMap[i] = nullptr;
			}
		}
		~HashTable(){
			for(int i = 0 ; i < SIZE ; i++){
				Node* head = dataMap[i];
				Node* temp = head;
				while(head){
					head = head -> next;
					delete temp;
					temp = head;
				}
			}
		}
		void printTable(){
			
			for(int i = 0 ; i < SIZE ; i++){
				cout << i <<": " << endl;
				if(dataMap[i]){
					Node* temp = dataMap[i];
					while(temp){
						cout << " {"<< temp->key <<", "<< temp->value << "}" <<endl;
						temp = temp->next;
					}
				}
			}
			
			/* 
			 // redundant version 
			 // has problem when time comes it overwrite the value so please research on it.
			for(int i = 0 ; i < SIZE ; i++){
				cout << i  << ":" << endl;
				while(dataMap[i]){
					cout << " {"<< dataMap[i] ->key <<", "<< dataMap[i] ->value<< "}" <<endl;
					dataMap[i] = dataMap[i] ->next;
				}
			}
			*/
		}
		
		int hash(string key){
			int hash = 0;
			for ( int i = 0 ; i < int(key.length()) ; i++ ){
				int asciiValue = int(key[i]);
				hash = (hash + asciiValue * 23) % SIZE;
			}
			return hash;
		}
		void set(string key , int value){
			int index = hash(key);
			Node* newNode = new Node(key,value);
			if(dataMap[index] == nullptr){
				dataMap[index] = newNode;
			}
			else{
				
				Node* temp = dataMap[index];
				while(temp->next){
					temp = temp->next;
				}
				temp->next =  newNode;
				
				/* 
				//will not work i have to research on it
				// overwrite first node
				while((dataMap[index])->next){
					dataMap[index] = (dataMap[index])->next;
				}
				(dataMap[index])->next =  newNode;
				*/ 
			}
		}
};
int main(){
	HashTable* myHashTable = new HashTable();
	myHashTable->set("nails",100);
	myHashTable->set("tile",50);
	myHashTable->set("lumber",80);
	
	myHashTable->set("bolts",200);
	myHashTable->set("screws",140);
	cout << "### Printing HashTable() : " << endl << endl;	
	myHashTable->printTable();
	cout << "### Printing HashTable() again : " << endl << endl;
	myHashTable->printTable();
}

