//https://www.geeksforgeeks.org/queue-linked-list-implementation/

#include "Queue.h"

    Queue::Queue()
    {
        numElements = 0;
        myLinkedList = new DoubleLinkedList<int>;
        ListNode* next;


    }

    Queue::~Queue()
    {
        //needs to be filled in
    }

    void Queue::insert(int inputData)
    {
         //add error checking
        myLinkedList->insertBack(inputData);
        ++numElements;
    }

    int Queue::remove()
    {
        //error checking
        --numElements;
        int c = myLinkedList->removeFront();
        return c;
    }

    bool Queue::isEmpty()
    {
        return (numElements == 0);   
    }

    int Queue::getSize()
    {
        return numElements;
    }