class DoubleLinkedList
{
    private:
        ListNode *front;
        ListNode *back;
        usigned int listSize;

    public:
        DoubleLinkedList();
        ~DoubleLinkedList();

        void insertFront(dataType insertedData);
        dataType removeFront(); //returns what it removes
        dataType removeBack(); //returns what it removes
        bool search(dataType dataToCheck); //returns true if list contains data
        dataType removeAtPosition(int position);

        unsigned int getSize();
        bool isEmpty();
        void printList(); //prints all values in the list

};