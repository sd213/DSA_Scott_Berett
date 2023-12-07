#include <iostream>
using namespace std;

class Node{
	public:
		string key;
		int value;
		Node* next;
		Node(string key,int value){
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
	
	
		void printTable(){
			for(int i = 0 ; i < SIZE ; i++){
				cout << i << ":" << endl;
				if(dataMap[i]){
					Node* temp = dataMap[i];
					while(temp){
						cout << " {"<< temp->key <<", "<< temp->value << "}" <<endl;
						temp = temp -> next;
					}
				}
			}
		}
		int hash(string key){
			int hash = 0;
			for(int i = 0; i < int(key.length());i++){
				int asciiValue = int(key[i]);
				hash = (hash + asciiValue * 23) % SIZE;  // here 23 is multiplied According to sir if you multiply by a prime number results gets more RANDOM
			}
			return hash;
		}
	
	
};
int main(){
	
	HashTable* myHashTable = new HashTable();
	cout << " ### only executing ( not storing ) hash function ###" << endl;
	cout << "keys: nails , " << " hash : " << myHashTable->hash("nails") << endl;
	cout << "keys: tile , " << " hash : " << myHashTable->hash("tile") << endl;
	cout << "keys: lumber , " << " hash : " << myHashTable->hash("lumber") << endl;
	cout << "keys: bolts , " << " hash : " << myHashTable->hash("bolts") << endl;
	cout << "keys: screws , " << " hash : " << myHashTable->hash("screws") << endl;
	
}
