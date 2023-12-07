#include<iostream>
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

class LinkedList{
        // by default access modifier is private in c++ class.
        Node* head;
        Node* tail;
        int length;
        public:
            LinkedList(int value){
                Node* newNode = new Node(value);
                head = newNode;
                tail = newNode;
                length = 1;
            }

            void PrintList();
            void PrintHead();
            void PrintTail();
            void PrintLength();
        
};
void LinkedList::PrintList(){
    Node* temp = head;
    while(temp!=nullptr){
        cout << temp->value << endl;
        temp = temp->next;
    }
}
void LinkedList::PrintHead(){
    cout << " head Value: "<< head->value << endl;
    cout << " head next: "<< head->next << endl;
}

void LinkedList::PrintTail(){
    cout << " tail Value: " << tail->value << endl;
    cout << " tail next : " << tail->next << endl;
}

void LinkedList::PrintLength(){
    cout << " Length of Linked List : " << length << endl;
}

// void LinkedList::PrintList(){    // don't uncomment this as redefinition of this function not allowed.
//     cout<< "Does not work" << endl;
// }

int main(){
    LinkedList* myLinkedlist1 = new LinkedList(43);//using new keyword or using dynamic memory allocation
    LinkedList myLinkedlist2(34);//using static memory allocation

    cout << "========= myLinkedlist1 =========" << endl;
    myLinkedlist1->PrintList();
    myLinkedlist1->PrintLength();
    myLinkedlist1->PrintHead();
    myLinkedlist1->PrintTail();
    
    cout << endl<<endl;
    cout << "========= myLinkedlist2 =========" << endl;
    myLinkedlist2.PrintList();
    myLinkedlist2.PrintLength();
    myLinkedlist2.PrintHead();
    myLinkedlist2.PrintTail();

    return 0;
}

/*
There are two ways of instantiating an object in C++ :

Static Memory Allocation
Dynamic Memory Allocation
Static memory allocation can be done as follows:

Suppose Shape is a class, then:

Shape triangle; //creates an object triangle of class Shape 
The above statement will create memory statically - implying at compile time. A MAJOR IMPLICATION of this is that in case you have a function that has such an object, then every time the function is called, the object declared will always be allotted the same memory address. A case where this may be a problem is when you have, suppose, a function where you are inserting a new node into a linked list. Here you want to create a new object of class Node each time and append it to the linked list. In that case static memory allocation will cause a problem, since it will not create “new” objects each time the function is called rather it will always use the same address that is allotted at compile time.
This is where Dynamic Memory Allocation comes to be useful. This can be done as follows:

Shape *triangle_ptr = new Shape(); 
Here, new keyword is used to allocate “new” memory address “dynamically” in the heap and return that address. Since the right hand side of the above statement returns an address of newly created object , we need to assign it to a pointer to that object as done above. If this statement is present in a function, then every time a new address location is returned.
*/
