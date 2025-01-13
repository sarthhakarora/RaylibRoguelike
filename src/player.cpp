#include "player.h"
#include "raylib.h"
#include <iostream>

Player::Player() {
    player.height = 60;
    player.width = 45;
    player.speed = 14.0f;
    player.movement = {0, 0};
    player.src = {0, 0, 15, 20};
    player.dest = {0, 0, player.width, player.height};
    player.textureRight = LoadTexture("../assets/player/playerRight.png");
    player.textureLeft = LoadTexture("../assets/player/playerLeft.png");
    player.currentTexture = player.textureRight;

}

std::vector<Rectangle> checkCollision(Rectangle playerRect, std::vector<Rectangle>& rectList, Vector2 worldPlayerPos)
{
    std::vector<Rectangle> hitList;

    size_t rect_List = rectList.size();

    // std::cout << rect_List << std::endl;

    if (!rectList.empty())
    {
       for (size_t i = 0; i < rect_List; i++)
       {
           if (CheckCollisionRecs(rectList[i], playerRect))
           {
               hitList.push_back(rectList[i]);
           }
       }
    }

    return hitList;
}


void Player::draw()
{
    DrawTexturePro(player.currentTexture, player.src, player.dest, Vector2{player.width/2, player.height/2}, 0.0f, WHITE);

}


void Player::update(Camera2D cam, std::vector<Rectangle> rectList)
{
    player.movement = {0, 0};

    /*
    -- MOVEMENT LOGIC
    -- THE TEXTURE OF THE PLAYER CHANGES DEPENDING ON IF THE PLAYER IS MOVING RIGHT OR LEFT
    */

    if (IsKeyDown(KEY_W)) {
        player.movement.y -= player.speed;

    }

    if (IsKeyDown(KEY_S)) {
        player.movement.y += player.speed;

    }

    if (IsKeyDown(KEY_D)) {
        player.movement.x += player.speed;
        player.currentTexture = player.textureRight;

    }

    if (IsKeyDown(KEY_A)) {
        player.movement.x -= player.speed;
        player.currentTexture = player.textureLeft;

    }

    player.dest.x += player.movement.x;
    hitList.clear();
    hitList = checkCollision(player.dest, rectList, GetWorldToScreen2D(Vector2{player.dest.x, player.dest.y}, cam));
    for (size_t i = 0; i < hitList.size(); i++) {
        if(player.movement.x > 0) {
            player.dest.x = hitList[i].x - (player.dest.width/2 + hitList[i].width/2 + 5.0f);
        }
        else if(player.movement.x < 0) {
            player.dest.x = hitList[i].x + (player.dest.width/2 + hitList[i].width/2 + 5.0f);

        }
    }

    player.dest.y += player.movement.y;
    hitList.clear();
    hitList = checkCollision(player.dest, rectList, GetWorldToScreen2D(Vector2{player.dest.x, player.dest.y}, cam));
    for (size_t i = 0; i < hitList.size(); i++) {

        if(player.movement.y > 0) {
            player.dest.y = hitList[i].y - (player.dest.height/2 + hitList[i].height/2 + 7.0f);

        }
        else if(player.movement.y < 0) {
            player.dest.y = hitList[i].y + (player.dest.height/2 + hitList[i].height/2);

        }
    }
        


}

void Player::unload()
{
    UnloadTexture(player.currentTexture);
    UnloadTexture(player.textureRight);
    UnloadTexture(player.textureLeft);

}
