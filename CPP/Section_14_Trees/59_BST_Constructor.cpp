#include <iostream>
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
		
	public:
		BinarySearchTree(){
			root = nullptr;
		}
		BinarySearchTree(int value){
			Node* newNode = new Node(value);
			root = newNode;
		}
	
		void getRoot(){
			cout << " Root of BinarySearchTree : " << root << endl;
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
	
	BinarySearchTree* myBST = new BinarySearchTree();
	myBST->getRoot();
	
	
	
	
	
	
	
	
}
