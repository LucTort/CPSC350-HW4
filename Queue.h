//Using assignment 3 and in class examples as reference

#include "DoubleLinkedList.cpp"

using namespace std;

class Queue
{
    public:
        Queue(); //default constructor
        ~Queue(); //destructor

        //core functions
        void insert(int data); //enqueu
        int remove(); //dequeue

        //aux functions
        int peek();
        bool isEmpty();
        int getSize();

        //vars
        // ListNode front; //aka head
        // ListNode rear; //aka tail
        int numElements;

        DoubleLinkedList<int> *myLinkedList; //LinkedLists are nice
};