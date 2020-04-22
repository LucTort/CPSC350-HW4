//https://www.geeksforgeeks.org/queue-linked-list-implementation/

#include "Queue.h"

    template<typename dataType>
    Queue<dataType>::Queue()
    {
        numElements = 0;
        myLinkedList = new DoubleLinkedList<dataType>;
        ListNode<dataType>* next;


    }

    template<typename dataType>
    Queue<dataType>::~Queue()
    {
        //needs to be filled in
    }

    template<typename dataType>
    void Queue<dataType>::insert(dataType inputData)
    {
         //add error checking
        myLinkedList->insertBack(inputData);
        ++numElements;
    }

    template<typename dataType>
    dataType Queue<dataType>::remove()
    {
        //error checking
        --numElements;
        dataType c = myLinkedList->removeFront();
        return c;
    }

    template<typename dataType>
    dataType Queue<dataType>::peek()
    {
        return myLinkedList->peekFront();
    }

    template<typename dataType>
    bool Queue<dataType>::isEmpty()
    {
        return (numElements == 0);   
    }

    template<typename dataType>
    int Queue<dataType>::getSize()
    {
        return numElements;
    }