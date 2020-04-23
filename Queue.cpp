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
        myLinkedList->~myLinkedList();
    }

    template<typename dataType>
    void Queue<dataType>::insert(dataType inputData)
    {
        myLinkedList->insertBack(inputData);
        ++numElements;
    }

    template<typename dataType>
    dataType Queue<dataType>::remove()
    {
        //error checking

        if (numElements > 0)
        {
            --numElements;
            dataType c = myLinkedList->removeFront();
            return c;
        }else
        {
            cout << "Error: Can't remove from an empty queue." << endl;
        }
    }

    template<typename dataType>
    dataType Queue<dataType>::peek()
    {
        if (numElements > 0)
        {
            return myLinkedList->peekFront();
        }
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