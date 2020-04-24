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

//     __  ___     __                            ____ __                           
//    /  |/  /__ _/ /_____   ___ __ _________   / _(_) /__   ___  ___  ___ ___  ___
//   / /|_/ / _ `/  '_/ -_) (_-</ // / __/ -_) / _/ / / -_) / _ \/ _ \/ -_) _ \(_-<
//  /_/  /_/\_,_/_/\_\\__/ /___/\_,_/_/  \__/ /_//_/_/\__/  \___/ .__/\__/_//_/___/
//                                                             /_/                 
    ifstream inputFile;
    inputFile.open(argv[1]);

    if (!inputFile.is_open()) //makes sure file opens correctly
        {
            cout << "File didn't open properly -- be sure you entered the name properly" << endl;
            return 1;
        }
    inputFile.close();

//     ___                         __                  ___         
//    / _ | ___  ___  ___ ___  ___/ / ___  ___ _    __/ (_)__  ___ 
//   / __ |/ _ \/ _ \/ -_) _ \/ _  / / _ \/ -_) |/|/ / / / _ \/ -_)
//  /_/ |_/ .__/ .__/\__/_//_/\_,_/ /_//_/\__/|__,__/_/_/_//_/\__/ 
//       /_/  /_/                                                  
    //appends a newline to the file, as per https://stackoverflow.com/questions/6932409/writing-a-string-to-the-end-of-a-file-c
    ofstream output;
    output.open(argv[1], ios::app);
    
    string str = "\n";
    output << str;
    output.close();

//     ___              __  ____ __   
//    / _ \___ ___ ____/ / / _(_) /__ 
//   / , _/ -_) _ `/ _  / / _/ / / -_)
//  /_/|_|\__/\_,_/\_,_/ /_//_/_/\__/ 
//                                    

    inputFile.open(argv[1]);


    //reads in data from file, puts it in queue for easier reference
    while (inputFile.get(currentChar)) // loop getting single characters
    {
        if(!(currentChar == '0' || currentChar == '1' || currentChar == '2' || currentChar == '3' || currentChar == '4' || currentChar == '5' || currentChar == '6' 
        || currentChar == '7' || currentChar == '8' || currentChar == '9' || '\n' || '\r'))
        {
            cout << "Error: Bad data. Only integer values are allowed. \"" << currentChar << "\" is not valid." << endl;
            return 1;
        }
        else
        {
            if (currentChar != '\n')
                {fileInputString += currentChar;}
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

    if(fileInputQueue->getSize() < 1) 
    {
        cout << "File contains no valid data." << endl; 
        return 1;
    }

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
            if(fileInputQueue->getSize() < 1) 
                {
                    cout << "Error: Data not formatted correctly." << endl; 
                    return 1;
                }

            studentQueue->insert(Stud(clockTick, fileInputQueue->remove()));
            if (studentQueue->getSize() > 0) {Stud currentStud = studentQueue->peek();}
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
        //test  cout << "It's time: " << tick << endl << endl;

//     ______          __      __                           _         __          
//    / __/ /___ _____/ /__   / /__ ___ __  _____   _    __(_)__  ___/ /__ _    __
//   _\ \/ __/ // / _  (_-<  / / -_) _ `/ |/ / -_) | |/|/ / / _ \/ _  / _ \ |/|/ /
//  /___/\__/\_,_/\_,_/___/ /_/\__/\_,_/|___/\__/  |__,__/_/_//_/\_,_/\___/__,__/ 
//                                                                                

    while(studentsAtWindows->getSize() > 0)
    {
        Stud currentStud = studentsAtWindows->remove(); //dequeues student so they can be "processed" *malicious chuckles*

        if (currentStud.getRemainingTicksNeeded() <= 0)//checks if student has been helped for their time
        {
             //test cout << currentStud.getAssignedWindow() << endl;
            availableWindows[currentStud.getAssignedWindow()].updateIsIdle(true);
            studentWaitTimes->insert(tick - currentStud.getTickToArrive() - currentStud.getStartingTicksNeeded()); //add to student wait time queue
            //test  cout << endl <<"students at windowz:"<< studentsAtWindows->getSize() << endl << endl;
        }else
        {
            helpedStudents->insert(currentStud);
        }
        
    }

    while(helpedStudents->getSize() > 0)
    {
        studentsAtWindows->insert(helpedStudents->remove());
    }

//     ___       __        __          __           __           _         __             
//    / _ \__ __/ /_  ___ / /___ _____/ /__   ___ _/ /_  _    __(_)__  ___/ /__ _    _____
//   / ___/ // / __/ (_-</ __/ // / _  (_-<  / _ `/ __/ | |/|/ / / _ \/ _  / _ \ |/|/ (_-<
//  /_/   \_,_/\__/ /___/\__/\_,_/\_,_/___/  \_,_/\__/  |__,__/_/_//_/\_,_/\___/__,__/___/
//                                                                                        
        for(int x = 0; x < numRegistrarWindows; ++x)
        {
            if (studentQueue->getSize() > 0)//if there is a student
            {
                Stud nextStud = studentQueue->peek();

                if (availableWindows[x].getIsIdle() && nextStud.getTickToArrive() <= tick)//if this window is idle and the student can arrive
                {
                     //test cout << "Put stud in window: " << x << endl;
                    studentQueue->remove();//deque the student
                    nextStud.assignWindow(x);
                    studentsAtWindows->insert(nextStud); //insert them in window queue
                    availableWindows[x].updateIsIdle(false);//mark window as occupied
                }
            }       
        }

//    _      ___         __             _    ____      __  _          
//   | | /| / (_)__  ___/ /__ _    __  (_)__/ / /__   / /_(_)_ _  ___ 
//   | |/ |/ / / _ \/ _  / _ \ |/|/ / / / _  / / -_) / __/ /  ' \/ -_)
//   |__/|__/_/_//_/\_,_/\___/__,__/ /_/\_,_/_/\__/  \__/_/_/_/_/\__/ 
//                                                                    
        for(int x = 0; x < numRegistrarWindows; ++x)
        {
            if(studentsAtWindows->getSize() > 0 || studentQueue->getSize() > 0) 
                {availableWindows[x].updateIdleTime();}
        }


//     ______          __         __                             __  __  _                  __           _         __          
//    / __/ /___ _____/ /__ ___  / /____   ___ ___  ___ ___  ___/ / / /_(_)_ _  ___   ___ _/ /_  _    __(_)__  ___/ /__ _    __
//   _\ \/ __/ // / _  / -_) _ \/ __(_-<  (_-</ _ \/ -_) _ \/ _  / / __/ /  ' \/ -_) / _ `/ __/ | |/|/ / / _ \/ _  / _ \ |/|/ /
//  /___/\__/\_,_/\_,_/\__/_//_/\__/___/ /___/ .__/\__/_//_/\_,_/  \__/_/_/_/_/\__/  \_,_/\__/  |__,__/_/_//_/\_,_/\___/__,__/ 
//                                          /_/                                                                                

        while(studentsAtWindows->getSize() > 0)
        {
            Stud currentStud = studentsAtWindows->remove(); //dequeues student so they can be "processed" *malicious chuckles*

             //test cout << currentStud.getRemainingTicksNeeded() << endl;

            currentStud.decreaseRemainingTicksNeeded();
            helpedStudents->insert(currentStud);
        }

        while(helpedStudents->getSize() > 0)
        {
            studentsAtWindows->insert(helpedStudents->remove());
        }



        //cout << "goign" << endl;

        //test //cout << endl <<"Students at windows: "<< studentsAtWindows->getSize() << endl;

         //test //cout << endl << "Students in queue: " << studentQueue->getSize() << endl;

        tick++;

         //test //getchar();

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
        if (studentWaitTimes->getSize() > 0)
        {
            if(studentWaitTimes->peek() > largestStudWaitTime)
                {largestStudWaitTime = studentWaitTimes->peek();}
        }

        totalStudWaitTime += studentWaitTimes->peek();

        if (studentWaitTimes->getSize() > 0)
        {
            if(studentWaitTimes->peek() > 10)
                {studsWaitingOverTenMin++;}
        }

        studWaitTimeArray[x] = studentWaitTimes->remove();
    }

    double meanStudWaitTime = ((double) totalStudWaitTime / (double) numStudWaitTimes);

//                  ___         
//    __ _  ___ ___/ (_)__ ____ 
//   /  ' \/ -_) _  / / _ `/ _ \
//  /_/_/_/\__/\_,_/_/\_,_/_//_/
//                              

    //sort the student times
    bool isSorted = false;
    while(!isSorted)
    {
        isSorted = true;

        for(int x = 0; x < numStudWaitTimes - 1; ++x)
        {
            if (studWaitTimeArray[x] > studWaitTimeArray[x + 1])
                {
                    int temp = studWaitTimeArray[x];
                    studWaitTimeArray[x] = studWaitTimeArray[x + 1];
                    studWaitTimeArray[x + 1] = temp;
                    isSorted = false;
                }
        }
    }

    for(int x = 0; x < numStudWaitTimes; ++x)
        {
             //test cout << studWaitTimeArray[x] << " ";
        }

    //pick the median value
    double medianStudentWaitTime = 0;
    if((numStudWaitTimes % 2) == 1) //it it's odd
    {
        medianStudentWaitTime = studWaitTimeArray[numStudWaitTimes / 2];
    }else
    {
        int leftValue = studWaitTimeArray[(numStudWaitTimes / 2) - 1];
        int rightValue = studWaitTimeArray[numStudWaitTimes / 2];
        medianStudentWaitTime = (((double) rightValue + (double) leftValue) / 2);
    }
    

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

    cout << endl << endl << "Calculated Student Data:" << endl;
    cout << "---------------------------" << endl;
    cout << "Mean student wait time: " << meanStudWaitTime << endl;
    cout << "Median student wait time: " << medianStudentWaitTime << endl;
    cout << "Longest student wait time: " << largestStudWaitTime << endl;
    cout << "Students waiting over ten minutes: " << studsWaitingOverTenMin << endl;
    cout << endl;

    cout << endl << "Calculated Window Data:" << endl;
    cout << "---------------------------" << endl;
    cout << "Mean window idle time: " << meanWindowIdleTime << endl;
    cout << "Longest window idle time: " << longestWindowIdleTime << endl;
    cout << "Number of windows idle over 5 minutes: " << numWindowsIdleOverFiveMin << endl;

    cout <<"  __  __             __                    __" << endl;
    cout <<" / /_/ /  ___ ____  / /__  __ _____  __ __/ /" << endl;
    cout <<"/ __/ _ \\/ _ `/ _ \\/  '_/ / // / _ \\/ // /_/ " << endl;
    cout <<"\\__/_//_/\\_,_/_//_/_/\\_\\  \\_, /\\___/\\_,_(_)  " << endl;
    cout <<"                         /___/               " << endl;
    cout << endl;

    
    

//                _                    __
//    __ _  ___ _(_)__    ___ ___  ___/ /
//   /  ' \/ _ `/ / _ \  / -_) _ \/ _  / 
//  /_/_/_/\_,_/_/_//_/  \__/_//_/\_,_/  
//                                       
}