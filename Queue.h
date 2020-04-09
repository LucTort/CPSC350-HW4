//Using assignment 3 and in class examples as reference

#include <iostream>
using namespace std;

template<typename dataType>
class Queue
{
    public:
        Queue(); //default constructor
        Queue(int queSize) //overloaded
        ~Queue() //destructor

        //core functions
        void insert(dataType data); //enqueu
        dataType remove(); //dequeue

        //aux functions
        dataType peek();
        bool isFull();
        bool isEmpty();
        int getSize();

        //vars
        int front; //aka head
        int rear; //aka tail
        int queueSize;

};