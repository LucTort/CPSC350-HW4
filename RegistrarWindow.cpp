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

void RegistrarWindow::updateIsIdle(bool idle)
{
    isIdle = idle;
}