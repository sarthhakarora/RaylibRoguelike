#include "startmenu.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include <iostream>

Startmenu::Startmenu() {
    menu.start = {100, 100, 300, 60};
}

bool Startmenu::drawMenu(bool gameActive)
{
    if (GuiButton(menu.start, "Start")) {
        gameActive = true;
    }
    
    return gameActive;
}
