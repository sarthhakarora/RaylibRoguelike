#include "weapon.h"
#include "raylib.h"
#include "raymath.h"
#include "enemy.h"
#include "score.h"

#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

Weapon::Weapon() {
    bow.angle = 0.0f;
    bow.width = 14;
    bow.height = 52;
    bow.src = {0, 0, 7, 26};
    bow.dest = {0, 0, bow.width, bow.height};
    bow.texture = LoadTexture("../assets/frames/weapon_bow.png");
    bow.direction = {0, 0};
    bow.firedelay = 0.5f;

};

void Weapon::draw() {
    // <------------------- DRAW CALL -------------------->
    DrawTexturePro(bow.texture, bow.src, bow.dest, Vector2{0.0f, bow.height/2}, bow.angle, WHITE);
    for (size_t i = 0; i < projectileList.size(); i++) {
        DrawTexturePro(projectileList[i].texture, projectileList[i].src, projectileList[i].dest, Vector2{projectileList[i].width/2, projectileList[i].height}, projectileList[i].angle, WHITE);

    }
    // <-------------------------------------------------->
}


void Weapon::update(Rectangle playerRect, Vector2 mousePos, std::vector<Enemy::enemyStats>& enemies) {
    // <------------------- BOW LOGIC -------------------->
    float radius = -40.0f; // THIS IS -70.0f DONT MAKE THIS 70.0f

    Vector2 playerPos = {playerRect.x, playerRect.y};

    Vector2 playerDirection = Vector2Normalize(Vector2Subtract(playerPos, mousePos));

    bow.angle = atan2(playerDirection.y, playerDirection.x) * RAD2DEG - 180.0f;

    // std::cout << bow.angle << std::endl;

    bow.dest.x = playerPos.x + radius * playerDirection.x;
    bow.dest.y = playerPos.y + radius * playerDirection.y;

    // <-------------------------------------------------->
    // <---------------- PROJECTILE LOGIC ---------------->
    if (IsMouseButtonPressed(0)) {   
        projectile.texture = bowTexture;
        projectile.width = 14.0f;
        projectile.height = 42.0f;
        projectile.speed = 8.5f;
        projectile.angle = bow.angle + 90.0f;
        projectile.direction = Vector2Subtract(mousePos, Vector2{playerRect.x, playerRect.y});
        projectile.velocity = Vector2Scale(Vector2Normalize(projectile.direction), projectile.speed);
        projectile.src = {0, 0, 7, 21};
        projectile.dest = {bow.dest.x, bow.dest.y, projectile.width, projectile.height};

        projectileList.push_back(projectile);
    }
    
    for (size_t i = 0; i < projectileList.size(); i++) {
        projectileList[i].dest.x += projectileList[i].velocity.x;
        projectileList[i].dest.y += projectileList[i].velocity.y;

    }
    // <-------------------------------------------------->
    // <------------------ COLLISIONS -------------------->

    collision = false;

    for(int i = 0; i < enemies.size(); i++) {
        for(int j = 0; j < projectileList.size(); j++){
            if (CheckCollisionRecs(projectileList[j].dest, enemies[i].dest)) {
                enemies.erase(enemies.begin() + i);
                projectileList.erase(projectileList.begin() + j);
                collision = true;

            }
        }
    }

    // <-------------------------------------------------->


}
