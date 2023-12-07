#include<iostream>

using namespace std;

class Node{
	public:
		int value;
		Node* left;
		Node* right;
		Node(int value){
			this->value = value;
			left = nullptr;
			right = nullptr;
		}
};
class BinarySearchTree{
	public:
		Node* root;
		
		BinarySearchTree(){
			root = nullptr;
		}
		BinarySearchTree(int value){
			Node* newNode = new Node(value);
			root = newNode;
		}
		
		bool insert(int value){
			Node* newNode = new Node(value);
			if(root == nullptr){
				root = newNode;
				return true;
			}
			Node* temp = root;
			while(true){
				if(temp->value == newNode->value) return false;
				if(temp->value < newNode->value){
					if(temp->right == nullptr){
						temp->right = newNode;
						return true;
					}
					temp = temp->right;
				}
				else{
					if(temp->left == nullptr){
						temp->left = newNode;
						return true;
					}
					temp = temp->left;
				}
			}
		}
		bool contains(int value){
			if(root == nullptr) return false;
			Node* newNode = new Node(value);
			Node* temp = root;
			
			while(temp!=nullptr){
				if(newNode->value > temp->value){
					temp = temp->right;
				}
				else if (newNode->value < temp->value){
					temp = temp->left;
				}
				else if (newNode->value == temp->value){
					return true;
				}
				
			}
			return false;
		}
		~BinarySearchTree() { destroy(root); }
		void destroy(Node* currentNode) {
            if (currentNode == nullptr) return;
            if (currentNode->left) destroy(currentNode->left);
            if (currentNode->right) destroy(currentNode->right);
            delete currentNode;
        }
};

int main(){
	BinarySearchTree* myBST = new BinarySearchTree(47);
	myBST->insert(47);
	myBST->insert(21);
	myBST->insert(76);
	myBST->insert(18);
	myBST->insert(52);
	myBST->insert(82);
	myBST->insert(27);
	
	cout << "Contains 27: " << myBST->contains(27)<< endl;
	cout << "Contains 17: " << myBST->contains(17);
	
	
	
	
	
	
	
	
	
	
	
}

