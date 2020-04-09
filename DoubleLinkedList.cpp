#include "DoubleLinkedList.h"

template<typename dataType>
DoubleLinkedList::DoubleLinkedList()
{
    listSize = 0;
    front == NULL;
}

template<typename dataType>
DoubleLinkedList::~DoubleLinkedList()
{
    //need to have list destroy istelf or something
}

template<typename dataType>
unsigned int DoubleLinkedList::getSize()
{
    return listSize;
}

template<typename dataType>
bool DoubleLinkedList::isEmpty()
{
    return (listSize == 0);
}

template<typename dataType>
void DoubleLinkedList::printList()
{
    ListNode *curr = front;

    while(curr != NULL)
    {
        cout << curr->listData << endl;
        curr = curr->next;
    }
}

template<typename dataType>
void DoubleLinkedList::insertFront(dataType dataToInsert)
{
    ListNode *node = new ListNode(dataToInsert)

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
void DoubleLinkedList::insertBack(dataType dataToInsert)
{
    ListNode *node = new ListNode(dataToInsert)

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
void DoubleLinkedList::removeFront(dataType dataToInsert)
{
    //make this, yeah?
}
