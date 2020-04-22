//Wyatt Miller
//Chris Chang
//Assignment 3
//Assignment 1
//https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
//https://stackoverflow.com/questions/7663709/how-can-i-convert-a-stdstring-to-int
//https://www.cplusplus.com/articles/D9j2Nwbp/
//https://stackoverflow.com/questions/6932409/writing-a-string-to-the-end-of-a-file-c
//https://www.tutorialspoint.com/cplusplus/cpp_passing_arrays_to_functions.htm
//https://stackoverflow.com/questions/28860967/pass-a-dynamic-array-of-objects-to-function
//https://stackoverflow.com/questions/21257544/c-wait-for-user-input


#include "RegistrarWindow.cpp"

//      ______                 __  _                 
//     / ____/_  ______  _____/ /_(_)___  ____  _____
//    / /_  / / / / __ \/ ___/ __/ / __ \/ __ \/ ___/
//   / __/ / /_/ / / / / /__/ /_/ / /_/ / / / (__  ) 
//  /_/    \__,_/_/ /_/\___/\__/_/\____/_/ /_/____/  
//                                                   

 bool getEmptyWindow(RegistrarWindow windows[], int numOfWindows)
 {
     for(int x = 0; x < numOfWindows; x++)
     {
        if (windows[x].getIsIdle())
            {return x;}
     }

     return -1;
 }
// {
//     for (int x = 0; x < numRegistrarWindows; ++x)
//     {
//         if (availableWindows[x].isHelpingStudent())
//             {return true;}
//             //cout << "in loop" << endl;
//     }

//     return false;
// }

//      __  ___      _     
//     /  |/  /___ _(_)___ 
//    / /|_/ / __ `/ / __ \
//   / /  / / /_/ / / / / /
//  /_/  /_/\__,_/_/_/ /_/ 
//                         

int main(int argc, char **argv)

{
    string fileInputString = "\0";
    int fileInputInt = '\0';
    char currentChar = '\0';


    Queue<int> *fileInputQueue = new Queue<int>;
    DoubleLinkedList<int> *myList = new DoubleLinkedList<int>;

//      ____                 ___                _______ __   
//     / __ \___  ____ _____/ (_)___  ____ _   / ____(_) /__ 
//    / /_/ / _ \/ __ `/ __  / / __ \/ __ `/  / /_  / / / _ \
//   / _, _/  __/ /_/ / /_/ / / / / / /_/ /  / __/ / / /  __/
//  /_/ |_|\___/\__,_/\__,_/_/_/ /_/\__, /  /_/   /_/_/\___/ 
//                                 /____/                    


    //appends a newline to the file, as per https://stackoverflow.com/questions/6932409/writing-a-string-to-the-end-of-a-file-c
    ofstream output;
    output.open(argv[1], ios::app);
    string str = "\n";
    output << str;
    output.close();

    ifstream inputFile;
    inputFile.open(argv[1]);

    //reads in data from file, puts it in queue for easier reference
    while (inputFile.get(currentChar)) // loop getting single characters
    {
        if (currentChar != '\n')
            fileInputString += currentChar;
        else
        {
            //this converts the string into an integer
            if (fileInputString != "\0")
            {
                if ( ! (istringstream(fileInputString) >> fileInputInt) ) fileInputInt = 0; //as per https://www.cplusplus.com/articles/D9j2Nwbp/
                fileInputString = "\0";
                fileInputQueue->insert(fileInputInt);
                //cout << fileInputInt << endl;
            }
        }
    }

    //cout << fileInputQueue->getSize() << endl;

//     _____      __                 _____ _                 __      __  _           
//    / ___/___  / /___  ______     / ___/(_)___ ___  __  __/ /___ _/ /_(_)___  ____ 
//    \__ \/ _ \/ __/ / / / __ \    \__ \/ / __ `__ \/ / / / / __ `/ __/ / __ \/ __ \
//   ___/ /  __/ /_/ /_/ / /_/ /   ___/ / / / / / / / /_/ / / /_/ / /_/ / /_/ / / / /
//  /____/\___/\__/\__,_/ .___/   /____/_/_/ /_/ /_/\__,_/_/\__,_/\__/_/\____/_/ /_/ 
//                     /_/                                                           

//     ____    __              ___           _     __                 _      ___         __             
//    / __/__ / /___ _____    / _ \___ ___ _(_)__ / /________ _____  | | /| / (_)__  ___/ /__ _    _____
//   _\ \/ -_) __/ // / _ \  / , _/ -_) _ `/ (_-</ __/ __/ _ `/ __/  | |/ |/ / / _ \/ _  / _ \ |/|/ (_-<
//  /___/\__/\__/\_,_/ .__/ /_/|_|\__/\_, /_/___/\__/_/  \_,_/_/     |__/|__/_/_//_/\_,_/\___/__,__/___/
//                  /_/              /___/                                                              

    int numRegistrarWindows = fileInputQueue->remove();
    RegistrarWindow availableWindows[numRegistrarWindows];
    Queue<Stud> *studentsAtWindows = new Queue<Stud>;   //Used to house students at windows

//     ____    __    ______          __         __        _        __   _         
//    / __/__ / /_  / __/ /___ _____/ /__ ___  / /____   (_)__    / /  (_)__  ___ 
//   _\ \/ -_) __/ _\ \/ __/ // / _  / -_) _ \/ __(_-<  / / _ \  / /__/ / _ \/ -_)
//  /___/\__/\__/ /___/\__/\_,_/\_,_/\__/_//_/\__/___/ /_/_//_/ /____/_/_//_/\__/ 
//                                                                                
    //sets up stud objects in a queue
    Queue<Stud> *studentQueue = new Queue<Stud>;

    while (fileInputQueue->getSize() >= 1)
    {
        int clockTick = fileInputQueue->remove();
        int numStuds = fileInputQueue->remove();
        for(int x = 0; x < numStuds; ++x)
        {
            studentQueue->insert(Stud(clockTick, fileInputQueue->remove()));
            Stud currentStud = studentQueue->peek();
        }
    }

    //testing only -- prints out the values
    // while(studentQueue->getSize() > 0)
    // {
    //     Stud studToPrint = studentQueue->remove();
    //     cout << studToPrint.getRemainingTicksNeeded() << " " << studToPrint.getTickToArrive() << endl;
    // }                                     

//      ____                 _____ _                 __      __  _           
//     / __ \__  ______     / ___/(_)___ ___  __  __/ /___ _/ /_(_)___  ____ 
//    / /_/ / / / / __ \    \__ \/ / __ `__ \/ / / / / __ `/ __/ / __ \/ __ \
//   / _, _/ /_/ / / / /   ___/ / / / / / / / /_/ / / /_/ / /_/ / /_/ / / / /
//  /_/ |_|\__,_/_/ /_/   /____/_/_/ /_/ /_/\__,_/_/\__,_/\__/_/\____/_/ /_/ 

    int tick = 0;
    Queue<int> *studentWaitTimes = new Queue<int>;  //stores data about how long students waited in line
    Queue<Stud> *helpedStudents = new Queue<Stud>;   //Queue used to house studs after they've been "processed" *evil laughter*

    while(studentQueue->getSize() > 0 || studentsAtWindows->getSize() > 0)//simulation loop
    {

//    __  __        __     __        ___           _     __                 _      ___         __             
//   / / / /__  ___/ /__ _/ /____   / _ \___ ___ _(_)__ / /________ _____  | | /| / (_)__  ___/ /__ _    _____
//  / /_/ / _ \/ _  / _ `/ __/ -_) / , _/ -_) _ `/ (_-</ __/ __/ _ `/ __/  | |/ |/ / / _ \/ _  / _ \ |/|/ (_-<
//  \____/ .__/\_,_/\_,_/\__/\__/ /_/|_|\__/\_, /_/___/\__/_/  \_,_/_/     |__/|__/_/_//_/\_,_/\___/__,__/___/
//      /_/                                /___/                                                              
        for(int x = 0; x < numRegistrarWindows; ++x)
        {

            Stud nextStud = studentQueue->peek();//get next student

            if (availableWindows[x].getIsIdle() 
                && studentQueue->getSize() > 0 \
                && nextStud.getTickToArrive() <= tick 
                && getEmptyWindow(availableWindows, numRegistrarWindows) != -1)//if window is idle -- insert student
            {
                cout << "Put studs in" << endl;
                nextStud = studentQueue->remove();//deque the student
                studentsAtWindows->insert(nextStud);
                availableWindows[getEmptyWindow(availableWindows, numRegistrarWindows)].updateIsIdle(false);//mark window as occupied

            }

            availableWindows[x].updateIdleTime();
        }

//    __  __        __     __        ______          __         __             __    _      ___         __          
//   / / / /__  ___/ /__ _/ /____   / __/ /___ _____/ /__ ___  / /____   ___ _/ /_  | | /| / (_)__  ___/ /__ _    __
//  / /_/ / _ \/ _  / _ `/ __/ -_) _\ \/ __/ // / _  / -_) _ \/ __(_-<  / _ `/ __/  | |/ |/ / / _ \/ _  / _ \ |/|/ /
//  \____/ .__/\_,_/\_,_/\__/\__/ /___/\__/\_,_/\_,_/\__/_//_/\__/___/  \_,_/\__/   |__/|__/_/_//_/\_,_/\___/__,__/ 
//      /_/     

        while(studentsAtWindows->getSize() > 0)
        {
            cout << endl <<"students at window1:"<< studentsAtWindows->getSize() << endl << endl;

            Stud currentStud = studentsAtWindows->remove(); //dequeues student so they can be "processed" *malicious chuckles*

            //cout << endl <<"students at window2:"<< studentsAtWindows->getSize() << endl << endl;

            cout << currentStud.getRemainingTicksNeeded() << endl;

            //cout << endl <<"students at window3:"<< studentsAtWindows->getSize() << endl << endl;

            if (currentStud.getRemainingTicksNeeded() > 0)//checks if student has been helped for their time
                {//if not, puts student back in window proces sing
                    currentStud.decreaseRemainingTicksNeeded();
                    helpedStudents->insert(currentStud);
                }
            else//otherwise doesn't put them back in queue, and updates the window they were at to be free
                {
                    availableWindows[currentStud.getAssignedWindow()].updateIsIdle(true);
                    cout << "Added"<<endl << "wait: " << tick - currentStud.getTickToArrive() - currentStud.getStartingTicksNeeded() << endl;
                    studentWaitTimes->insert(tick - currentStud.getTickToArrive() - currentStud.getStartingTicksNeeded()); //add to student wait time queue
                }

            cout << endl <<"students at windowz:"<< studentsAtWindows->getSize() << endl << endl;
        }

        while(helpedStudents->getSize() > 0)
        {
            studentsAtWindows->insert(helpedStudents->remove());
        }



        //cout << "goign" << endl;

        cout << endl <<"Students at windows at end: "<< studentsAtWindows->getSize() << endl << endl;

        cout << endl << "Students in queue at end: " << studentQueue->getSize() << endl << endl;

        tick++;

        getchar();

    }//tick loop

//     ______      __           __      __          ________          __     _____ __        ________
//    / ____/___ _/ /______  __/ /___ _/ /____     /_  __/ /_  ____ _/ /_   / ___// /___  __/ __/ __/
//   / /   / __ `/ / ___/ / / / / __ `/ __/ _ \     / / / __ \/ __ `/ __/   \__ \/ __/ / / / /_/ /_  
//  / /___/ /_/ / / /__/ /_/ / / /_/ / /_/  __/    / / / / / / /_/ / /_    ___/ / /_/ /_/ / __/ __/  
//  \____/\__,_/_/\___/\__,_/_/\__,_/\__/\___/    /_/ /_/ /_/\__,_/\__/   /____/\__/\__,_/_/ /_/     
//                                                                                                   

//     ______          __     __     __      
//    / __/ /___ _____/ / ___/ /__ _/ /____ _
//   _\ \/ __/ // / _  / / _  / _ `/ __/ _ `/
//  /___/\__/\_,_/\_,_/  \_,_/\_,_/\__/\_,_/ 
//                                           

    int largestStudWaitTime = 0;
    int totalStudWaitTime = 0;
    int studsWaitingOverTenMin = 0;
    int numStudWaitTimes = studentWaitTimes->getSize();
    int studWaitTimeArray [numStudWaitTimes];

    for (int x = 0; x < numStudWaitTimes; ++x)//puts values in array, and gets other data
    {
        cout << studentWaitTimes->peek() << endl;
        if(studentWaitTimes->peek() > largestStudWaitTime)
            {largestStudWaitTime = studentWaitTimes->peek();}

        totalStudWaitTime += studentWaitTimes->peek();

        if(studentWaitTimes->peek() > 10)
            {studsWaitingOverTenMin++;}

        studWaitTimeArray[x] = studentWaitTimes->remove();
    }

    double meanStudWaitTime = ((double) totalStudWaitTime / (double) numStudWaitTimes);

//    _      ___         __                __     __      
//   | | /| / (_)__  ___/ /__ _    __  ___/ /__ _/ /____ _
//   | |/ |/ / / _ \/ _  / _ \ |/|/ / / _  / _ `/ __/ _ `/
//   |__/|__/_/_//_/\_,_/\___/__,__/  \_,_/\_,_/\__/\_,_/ 
//            

    int longestWindowIdleTime = 0;
    int totalWindowIdleTime = 0;
    int numWindowsIdleOverFiveMin = 0;

    for(int x = 0; x < numRegistrarWindows; ++x)
    {
        totalWindowIdleTime += availableWindows[x].getIdleTime();

        if (availableWindows[x].getIdleTime() > longestWindowIdleTime)
            {longestWindowIdleTime = availableWindows[x].getIdleTime();}

        if (availableWindows[x].getIdleTime() > 5)
            {numWindowsIdleOverFiveMin++;}
    }

    double meanWindowIdleTime = ((double) totalWindowIdleTime / (double) numRegistrarWindows);

//     ____        __              __     ____        __        __
//    / __ \__  __/ /_____  __  __/ /_   / __ \____ _/ /_____ _/ /
//   / / / / / / / __/ __ \/ / / / __/  / / / / __ `/ __/ __ `/ / 
//  / /_/ / /_/ / /_/ /_/ / /_/ / /_   / /_/ / /_/ / /_/ /_/ /_/  
//  \____/\__,_/\__/ .___/\__,_/\__/  /_____/\__,_/\__/\__,_(_)   
//                /_/                                             

    cout << endl << "Calculated Student Data:" << endl << endl;
    cout << "Mean student wait time: " << meanStudWaitTime << endl;
    //need median
    cout << "Longest student wait time: " << largestStudWaitTime << endl;
    cout << "Students waiting over ten minutes: " << studsWaitingOverTenMin << endl;

    cout << endl << "Calculated Window Data:" << endl << endl;
    cout << "Mean window idle time: " << meanWindowIdleTime << endl;
    cout << "Longest window idle time: " << longestWindowIdleTime << endl;
    cout << "Number of windows idle over 5 minutes: " << numWindowsIdleOverFiveMin << endl;

    cout <<"  __  __             __                    __" << endl;
    cout <<" / /_/ /  ___ ____  / /__  __ _____  __ __/ /" << endl;
    cout <<"/ __/ _ \\/ _ `/ _ \\/  '_/ / // / _ \\/ // /_/ " << endl;
    cout <<"\\__/_//_/\\_,_/_//_/_/\\_\\  \\_, /\\___/\\_,_(_)  " << endl;
    cout <<"                         /___/               " << endl;
    cout << endl;

    
    


}//end of main


