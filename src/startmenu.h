#ifndef STARTMENU_H
#define STARTMENU_H

#include "raylib.h"

class Startmenu {
public:
    struct Menu
    {
        Rectangle start; 
    } menu;
    
    Startmenu();
    bool drawMenu(bool gameActive);
};

#endif 