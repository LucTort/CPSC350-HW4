#include "ListNode.h"

template<typename dataType>
ListNode<dataType>::ListNode()
{
    next = NULL;
    previous = NULL;
}

template<typename dataType>
ListNode<dataType>::ListNode(dataType inputData)
{
    nodeData = inputData;
    next = NULL;
    previous = NULL;
}

template<typename dataType>
ListNode<dataType>::~ListNode()
{

}