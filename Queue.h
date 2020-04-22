//Using assignment 3 and in class examples as reference

#include "DoubleLinkedList.cpp"

using namespace std;

template<typename dataType>
class Queue
{
    public:
        Queue(); //default constructor
        ~Queue(); //destructor

        //core functions
        void insert(dataType data); //enqueu
        dataType remove(); //dequeue

        //aux functions
        dataType peek();
        bool isEmpty();
        int getSize();

        //vars
        // ListNode front; //aka head
        // ListNode rear; //aka tail
        int numElements;

        DoubleLinkedList<dataType> *myLinkedList; //LinkedLists are nice
};