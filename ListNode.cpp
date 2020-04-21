#include "ListNode.h"

ListNode::ListNode()
{
    next = NULL;
    previous = NULL;
}

ListNode::ListNode(int inputData)
{
    nodeData = inputData;
    next = NULL;
    previous = NULL;
}

ListNode::~ListNode()
{
    
}