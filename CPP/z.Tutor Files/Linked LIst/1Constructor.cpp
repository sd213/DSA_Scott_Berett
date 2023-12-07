#include <iostream>

class Node
{

public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
    }
};
class LinkedList{
    private:
        Node* head; //head pointing to node
        Node* tail; // tail pointing to last node
        int length; // to keep track of node's length
    public:
    LinkedList(int value){ 
        //create new node for first time
        Node* newNode = new Node(value);
        //For first time both head and tail assigns to newNode pointer object.
        head = newNode;
        tail = newNode;
        length=1;
    }
    void append(int  value){
        //create new node
        // add node to end
    }
    void prepend(int value){
        // create new node 
        // add that node to beginning
    }
    bool insert(int index,int value){
        //create new node
        //insert node at particular index
        return 0;
    }
};


// nullptr is a keyword that represents zero as an address (its type is considered a pointer-type), while NULL is the value zero as an int

int main(){
    //Creating Linkedlist Object.
    LinkedList* myLinkedList = new LinkedList(4);

    return 0;
}