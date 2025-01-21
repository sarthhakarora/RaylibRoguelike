#include "player.h"
#include "enemy.h"
#include "timer.h"
#include "raylib.h"

#include <iostream>

Player::Player() {
    // PLAYER
    player.height = 60;
    player.width = 45;
    player.playerInvincible = 5.0;
    player.speed = 14.0f;
    player.health = 2;
    player.maxHealth = 2;
    player.movement = {0, 0};
    player.src = {0, 0, 15, 20};
    player.dest = {0, 0, player.width, player.height};
    player.textureRight = LoadTexture("../assets/player/playerRight.png");
    player.textureLeft = LoadTexture("../assets/player/playerLeft.png");
    player.currentTexture = player.textureRight;
    player.tint = WHITE;
    
    
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
    DrawTexturePro(
        player.currentTexture,
        player.src, player.dest,
        Vector2{player.width/2, player.height/2},
        0.0f,
        player.tint);

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

void Player::healthDraw()
{
    for (size_t i = 0; i < healthList.size(); i++) {
        DrawTexturePro(
            healthList[i].currentTexture,
            healthList[i].src,
            healthList[i].dest,
            Vector2{healthList[i].width/2,
            healthList[i].height/2},
            0.0f,
            WHITE);     

    }
    
}

bool Player::healthUpdate(std::vector<Enemy::enemyStats> &enemies, bool gameActive)
{
    for (size_t i = 0; i < enemies.size(); i++) {
        if (CheckCollisionRecs(enemies[i].dest, player.dest)) {
            if(playerTimer.timerDone(&timer)) {
                player.health--;

            } 
        
            playerTimer.startTimer(&timer, 2.0f);
            if (player.health <= 0) {
                player.health = 0;

            }
            break;

        }

        // Give the player a RED tint to show that they have been hit and that they are invincible for 2 secs so they can move.
        if (playerTimer.timerDone(&timer)) {
            player.tint = WHITE;

        } 

        if (!playerTimer.timerDone(&timer)) {
            player.tint = RED;

        }

    }

    playerTimer.updateTimer(&timer);

    if (healthList.size() != player.health) {
        healthList.clear(); 
        for (size_t i = 0; i < player.health; i++) {
            health.height = 36;
            health.width = 39;
            health.fullHeartTexture = fullHeartTexture;
            health.emptyHeartTexture = emptyHeartTexture;
            health.currentTexture = health.fullHeartTexture;
            health.src = {0, 0, 13, 12};
            health.dest = {30 + (health.width * i + i * 7), 608 - 5 - health.height, health.width, health.height};

            healthList.push_back(health);
             
        }

    }

    if (player.health <= 0) {
        enemies.clear();
        player.dest.x = 0;
        player.dest.y = 0;
        player.health = player.maxHealth;
        gameActive = false;

    }

    return gameActive;
}
