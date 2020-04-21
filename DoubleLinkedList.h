#include "ListNode.cpp"

template<typename dataType>
class DoubleLinkedList
{
    private:
        ListNode *front;
        ListNode *back;
        unsigned int listSize;

    public:
        DoubleLinkedList();
        ~DoubleLinkedList();

        void insertFront(int insertedData);
        void insertBack(int insertedData);
        dataType removeFront(); //returns what it removes
        int removeBack(); //returns what it removes
        bool search(int dataToCheck); //returns true if list contains data
        int removeAtPosition(int position);
        int removeFront(int dataToInsert);

        unsigned int getSize();
        bool isEmpty();
        void printList(); //prints all values in the list

};