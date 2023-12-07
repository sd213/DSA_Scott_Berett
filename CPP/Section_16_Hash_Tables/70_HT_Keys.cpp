#include <iostream>
#include <vector>
using namespace std;

class Node{
	public:
		string key;
		int value;
		Node* next;
		Node(string key , int value){
			this->key = key ;
			this->value = value;
			next = nullptr;
		}
	
};
class HashTable{
	private:
		static const int SIZE = 7;
		Node* dataMap[SIZE];
		int hash(string key){
			int hash = 0;
			for(int i = 0 ; i < int(key.length()) ; i++){
				int asciiValue = int(key[i]);
				hash = (hash + asciiValue * 23) % SIZE;
			}
			return hash;
		}
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
				cout << i << ":" << endl;
				if(dataMap[i] != nullptr){
					Node* temp = dataMap[i];
					while(temp){
						cout << "{ key: " << temp->key << " , value: " << temp->value << " }" << endl;
						temp = temp->next;
					}
				}
			}
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
				temp->next = newNode;
			}
		}
		int get(string key){
			int index = hash(key);
			Node* temp = dataMap[index];
			while(temp){
				if(temp->key == key ) return temp->value;
				temp = temp->next;
			}
			return 0;
		}
		vector<string> keys(){
			vector<string> allkeys;
			for(int i = 0 ; i < SIZE ; i++){
				Node* temp = dataMap[i];
				while(temp){
					allkeys.push_back(temp->key);
					temp = temp->next;
				}
			}
			return allkeys;
		}
	
};

int main(){
	HashTable* myHashTable = new HashTable();
	myHashTable->set("nails",100);
	myHashTable->set("tile",50);
	myHashTable->set("lumber",80);
	myHashTable->set("bolts",200);
	myHashTable->set("screws",140);
	myHashTable->printTable();
	
	cout << "#### Checking if the Keys are present ####" << endl;
	cout << " Lumber: " << myHashTable->get("lumber") << endl;
	cout << " Bolts : "  << myHashTable->get("bolts") << endl;
	cout << " Hammer : "  << myHashTable->get("Hammer") << endl;
	
	vector<string> myKeys = myHashTable->keys();
	for(auto key : myKeys){
		cout << key << " ";
	}
}
