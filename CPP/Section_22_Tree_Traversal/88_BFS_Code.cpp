#include <iostream>
#include <queue>

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
                if(temp -> value < newNode->value){
                    if(temp->right == nullptr){
                        temp->right = newNode;
                        return true;
                    }
                    temp = temp -> right;
                }
                else{
                    if(temp->left == nullptr){
                        temp -> left = newNode;
                        return true;
                    }
                    temp = temp -> left;
                }
            }
                return false;
        }
        bool contains(int value){
            if(root == nullptr) return false;
            Node* temp = root;
            while (temp){
                if(temp->value == value) return true;
                if(temp->value < value){
                    temp = temp -> right;
                }
                else{
                    temp = temp -> left;
                }
            }
            return false;
        }
        
        void BFS(){
            queue<Node*> myQueue;
            myQueue.push(root);
            while(myQueue.size() > 0){
                Node* currentNode = myQueue.front();
                myQueue.pop();
                cout << currentNode ->value << " ";
                if(currentNode->left != nullptr){
                    myQueue.push(currentNode->left);
                }
                if(currentNode->right != nullptr){
                    myQueue.push(currentNode->right);
                }
            }
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
	cout << "Contains 17: " << myBST->contains(17) << endl;

    myBST->BFS();

}