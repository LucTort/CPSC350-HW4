#include "Stud.cpp"

class RegistrarWindow
{
    private:
        int idleTime;
        bool isIdle;

    public:
        RegistrarWindow(); //default constructor
        void updateIdleTime();
        void updateIsIdle(bool);
        bool getIsIdle();
        int getIdleTime();


      ~RegistrarWindow();
};