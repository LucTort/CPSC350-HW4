#include "DoubleLinkedList.h"

template<typename dataType>
DoubleLinkedList<dataType>::DoubleLinkedList()
{
    listSize = 0;
    front == NULL;
}

template<typename dataType>
DoubleLinkedList<dataType>::~DoubleLinkedList()
{
    
}

template<typename dataType>
unsigned int DoubleLinkedList<dataType>::getSize()
{
    return listSize;
}

template<typename dataType>
bool DoubleLinkedList<dataType>::isEmpty()
{
    return (listSize == 0);
}

template<typename dataType>
void DoubleLinkedList<dataType>::printList()
{
    ListNode<dataType> *curr = front;

    while(curr != NULL)
    {
        cout << curr->nodeData << endl;
        curr = curr->next;
    }
}

template<typename dataType>
void DoubleLinkedList<dataType>::insertFront(dataType dataToInsert)
{
    ListNode<dataType> *node = new ListNode<dataType>(dataToInsert);
    //node.nodeData = dataToInsert;

    if(isEmpty())
    {
        back = node;
    }else
    {
        front->previous = node;
        node->next = front;
    }
    front = node;

    listSize++;
}

template<typename dataType>
void DoubleLinkedList<dataType>::insertBack(dataType dataToInsert)
{
    ListNode<dataType> *node = new ListNode<dataType>(dataToInsert);

    if(isEmpty())
    {
        front = node;
    }else
    {
        back->next = node;
        node->previous = back;
    }
    back = node;

    listSize++;
}

template<typename dataType>
dataType DoubleLinkedList<dataType>::removeFront()
{
    ListNode<dataType> *node = front;

    if (front->next == NULL)
    {
        back = NULL;
    }else
    {
        front = front->next;
    }

    node->next = NULL;

    listSize--;

    return node->nodeData;
}

template<typename dataType>
dataType DoubleLinkedList<dataType>::peekFront()
{
    ListNode<dataType> *node = front;
    return node->nodeData;
}
