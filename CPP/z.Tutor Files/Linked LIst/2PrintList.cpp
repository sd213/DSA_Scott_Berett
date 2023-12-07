#include <iostream>
using namespace std;

class Node{
    public:
        int value;
        Node* next;

        Node(int value){
            this-> value = value;
            next = nullptr;
        }
};

class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;
    public:
        LinkedList(int value){
            Node* firstNode = new Node(value);
            head = firstNode;
            tail = firstNode;
            length = 1;
        }
        void printList(){
            Node* temp = head;
            int pos = 1;
            cout<<" head: "<< head->value<<endl;
            cout<<" tail: "<< tail->value<<endl;
            cout<<" length: "<< length <<endl;
            while(temp != nullptr){
                cout<< "value at " << pos <<" is "<<temp-> value<<endl;
                temp = temp->next;
                pos ++;
            }
        }
};

int main(){
    LinkedList* myLinkedList = new LinkedList(2);
    

    cout<<" Calling First LinkedList:---- "<< endl;
    myLinkedList->printList();
    



    return 0;

}