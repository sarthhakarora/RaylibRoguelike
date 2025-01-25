#ifndef STARTMENU_H
#define STARTMENU_H

#include "raylib.h"

class Startmenu {
public:
    struct Button
    {
        Rectangle src;
        Rectangle dest; 
        Texture texture;

    } startButton;
    
    Startmenu();
    void drawMenu();
    void update(bool& gameActive, Vector2 mousePos);
};

#endif 