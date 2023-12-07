// ONLY NEXT  ATTRIBUTE USED TO SHOW THE VALUE OF LINKED LIST NOTE
#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        Node* next;
        Node(int value){
            this-> value = value;
            next = nullptr;
        }
};
int main(){
    //creating node pointer
    Node* thist = new Node(23);
    Node* thist1= new Node(234);
    Node* thist2 = new Node(2324);    
    Node* thist3= new Node(53554);
    Node* thist4= new Node(762);

    // thist->next=thist1->next=thist2->next=thist3->next=thist4; //will generater error
/*  
    thist->next = thist1;
    thist1->next = thist2;
    thist2-> next = thist3;
    thist3-> next = thist4;
    // it can also be written as
*/
    thist->next=thist1;
    thist->next->next = thist2;
    thist->next->next->next = thist3;
    thist->next->next->next->next = thist4;
    cout<<"The values are : - " << endl;
    cout << thist-> value << endl << thist->next->value << endl << thist->next->next->value << endl << thist->next-> next->next->value << endl<< thist->next->next->next->next->value;
}