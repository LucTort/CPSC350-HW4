#include 

template<typename dataType>
ListNode::ListNode()
{
    next = NULL;
    previous = NULL;
}

template<typename dataType>
ListNode::ListNode(dataType inputData)
{
    nodeData = inputData;
    next = NULL;
    previous = NULL;
}