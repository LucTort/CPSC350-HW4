
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