// IN LINKED LIST ASSIGNING DIFFERENT NODE CLASS TYPE WITH NEXT
#include <iostream>
using namespace std;

class Node1
{
public:
    int value;
    Node1 *next;
    Node1(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class Node2
{
public:
    int value;
    Node2 *next;
    Node2(int value)
    {
        this->value = value;
        next = nullptr;
    }
};
int main()
{
    // creating node pointer
    Node1 *thist = new Node1(23);
    Node1 *thist1 = new Node1(234);
    Node1 *thist2 = new Node1(2324);
    Node2 *thist3 = new Node2(53554);
    Node2 *thist4 = new Node2(762);

    // thist->next=thist1->next=thist2->next=thist3->next=thist4; //will generater error
    /*
        thist->next = thist1;
        thist1->next = thist2;
        thist2-> next = thist3;
        thist3-> next = thist4;

    */
    // it can also be written as
    thist->next = thist1;
    thist->next->next = thist2;
    thist->next->next->next = thist3; // a value of type "Node2 *" cannot be assigned to an entity of type "Node1 *"C/C++(513)
    thist->next->next->next->next = thist4; // a value of type "Node2 *" cannot be assigned to an entity of type "Node1 *"C/C++(513)

    cout << "The values are : - " << endl;
    cout << thist->value << endl
         << thist->next->value << endl
         << thist->next->next->value << endl
         << thist->next->next->next->value << endl
         << thist->next->next->next->next->value;
}