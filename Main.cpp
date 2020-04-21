//Wyatt Miller
//Chris Chang
//Assignment 3


#include "Queue.cpp"

int main(int argc, char **argv)

{
    int registrarWindows = '\0';
    char currentChar = '\0';

    Queue *myQueue = new Queue;
    DoubleLinkedList<int> *myList = new DoubleLinkedList<int>;

//      ____                 ___                _______ __   
//     / __ \___  ____ _____/ (_)___  ____ _   / ____(_) /__ 
//    / /_/ / _ \/ __ `/ __  / / __ \/ __ `/  / /_  / / / _ \
//   / _, _/  __/ /_/ / /_/ / / / / / /_/ /  / __/ / / /  __/
//  /_/ |_|\___/\__,_/\__,_/_/_/ /_/\__, /  /_/   /_/_/\___/ 
//                                 /____/                    

    ifstream inputFile;
    inputFile.open(argv[1]);
    while (inputFile.get(currentChar)) // loop getting single characters
    {
        if (registrarWindows == '\0') 
        registrarWindows = (int) currentChar;
        cout << currentChar << endl;
    }
    cout << endl <<registrarWindows << endl;

}