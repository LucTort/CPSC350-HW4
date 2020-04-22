#include "RegistrarWindow.h"

RegistrarWindow::RegistrarWindow()
{
    idleTime = 0;
    isIdle = true;
}

RegistrarWindow::~RegistrarWindow()
{
    
}

bool RegistrarWindow::getIsIdle()
{
    return isIdle;
}

int RegistrarWindow::getIdleTime()
{
    return idleTime;
}

void RegistrarWindow::updateIsIdle(bool idle)
{
    isIdle = idle;
}

void RegistrarWindow::updateIdleTime()
{
    if (isIdle)
        {idleTime++;}
}