#include<iostream>
#include<queue>
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
        void insert(int value){
            Node* newNode = new Node(value);
            if(root == nullptr){
                root = newNode;
                return ;
            }
            Node* temp = root;
            while(true){
                if(temp->value == value) return;
                if(temp->value < value){
                    if(temp->right == nullptr){
                        temp->right = newNode;
                        return;
                    }
                    temp = temp->right;
                }
                else{
                    if(temp->left == nullptr){
                        temp->left = newNode;
                        return;
                    }
                    temp = temp->left;
                }
            }
        }
        bool contains(int value){
            if(root == nullptr) return false;
            Node* temp = root;
            while(temp){
                if(temp->value == value) return true;
                if(temp->value < value){
                    temp = temp->right;
                }
                else{
                    temp = temp->left;
                }
            }
            return false;
        }
        void BFS(){
            queue<Node*> myQueue;
            myQueue.push(root);
            while(myQueue.size()>0){
                Node* CurrentNode = myQueue.front();
                myQueue.pop();
                cout << CurrentNode->value << " " ;
                if(CurrentNode->left){
                    myQueue.push(CurrentNode->left);
                }
                if(CurrentNode->right){
                    myQueue.push(CurrentNode->right);
                }
            }
        }
        void DFSPreOrder(Node* CurrentNode){
            cout << CurrentNode->value << " " ;
            if(CurrentNode->left){
                DFSPreOrder(CurrentNode->left);
            }
            if(CurrentNode->right){
                DFSPreOrder(CurrentNode->right);
            }
        }
        void DFSPreOrder(){
            DFSPreOrder(root);
        }
        void DFSPostOrder(Node* CurrentNode){
            if(CurrentNode->left){
                DFSPostOrder(CurrentNode->left);
            }
            if(CurrentNode->right){
                DFSPostOrder(CurrentNode->right);
            }
            cout << CurrentNode->value << " ";
        }

        void DFSPostOrder(){
            DFSPostOrder(root);
        }

        void DFSInOrder(Node* CurrentNode){
            if(CurrentNode->left){
                DFSInOrder(CurrentNode->left);
            }
            cout << CurrentNode->value << " ";
            if(CurrentNode->right){
                DFSInOrder(CurrentNode->right);
            }
        }

        void DFSInOrder(){
            DFSInOrder(root);
        }    

         void destroy(Node* currentNode) {
            if (currentNode == nullptr) return;
            if (currentNode->left) destroy(currentNode->left);
            if (currentNode->right) destroy(currentNode->right);
            delete currentNode;
        }
        
         Node* getRoot() {
            return root;
        } 

        ~BinarySearchTree() { destroy(root); }    
};
int main(){
     BinarySearchTree* myBST = new BinarySearchTree(47);
	myBST->insert(47);
	myBST->insert(21);
	myBST->insert(76);
	myBST->insert(18);
	myBST->insert(27);
	myBST->insert(52);
	myBST->insert(82);
	
	
    cout << "BFS : " << endl;
    myBST->BFS();
    cout << endl;

    cout << "DFS PreOrder : " << endl;
    myBST->DFSPreOrder();
    cout << endl;

    cout << "DFS PostOrder: " << endl;
    myBST->DFSPostOrder();
    cout << endl;

    cout << "DFS InOrder: " << endl;
    myBST->DFSInOrder();
    cout << endl;

}
