#include "ListNode.cpp"

template<typename dataType>
class DoubleLinkedList
{
    private:
        ListNode<dataType> *front;
        ListNode<dataType> *back;
        unsigned int listSize;

    public:
        DoubleLinkedList();
        ~DoubleLinkedList();

        void insertFront(dataType insertedData);
        void insertBack(dataType insertedData);
        dataType removeFront(); //returns what it removes
        int removeBack(); //returns what it removes
        bool search(int dataToCheck); //returns true if list contains data
        int removeAtPosition(int position);
        int removeFront(int dataToInsert);
        dataType peekFront();

        unsigned int getSize();
        bool isEmpty();
        void printList(); //prints all values in the list

};