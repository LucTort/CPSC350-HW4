#include <iostream>
#include <fstream> //Needed to work with files
#include <string>
#include <stdlib.h> 
#include <sstream>
#include <iomanip>

using namespace std;

template<typename dataType>
class ListNode
{
    public:
        dataType nodeData;
        ListNode *next;
        ListNode *previous;

        ListNode(); //default constructor
        ListNode(dataType inputData);

      ~ListNode();
};