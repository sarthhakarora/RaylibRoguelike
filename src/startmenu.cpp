#include "startmenu.h"
#include "raylib.h"
#include <iostream>

Startmenu::Startmenu() {
    startButton.src = {0, 0, 31, 12};
    startButton.dest = {800/2-31*5/2, 300, 31*5, 12*5};
    startButton.texture = LoadTexture("../assets/ui/start.png");

}

void Startmenu::drawMenu()
{
    DrawTexturePro(startButton.texture, startButton.src, startButton.dest, Vector2{0.0f, 0.0f}, 0.0f, WHITE);
    DrawTextPro(GetFontDefault(), "Raylib Rougelike", Vector2{270, 100}, Vector2{0, 0}, 0.0f, 30, 3, RED);
    

}

void Startmenu::update(bool& gameActive, Vector2 mousePos)
{    
    if(CheckCollisionPointRec(mousePos, startButton.dest) && IsMouseButtonDown(0) || IsKeyDown(KEY_SPACE)) {
        gameActive = true;

    }
}
