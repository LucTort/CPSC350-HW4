#include <iostream>
#include <fstream> //Needed to work with files
#include <string>

using namespace std;

class ListNode
{
    public:
        int nodeData;
        ListNode *next;
        ListNode *previous;

        ListNode(); //default constructor
        ListNode(int inputData);

      ~ListNode();
};