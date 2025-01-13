#ifndef WEAPON_H
#define WEAPON_H

#include "raylib.h"
#include "enemy.h"
#include <vector>
#include <iostream>


class Weapon {
public:
    Weapon();

    struct weaponStats
    {
        Texture2D texture;
        float height;
        float width;
        float firedelay;
        float angle;
        Rectangle src;
        Rectangle dest;
        Vector2 direction;
        
    };
    struct Projectile
    {
        float height;
        float width;
        Texture2D texture;
        Vector2 direction;
        Vector2 velocity;
        float speed;
        float angle;
        Rectangle src;
        Rectangle dest;
        std::vector<Rectangle> rectList;

    }; 

    weaponStats bow;

    Texture2D bowTexture = LoadTexture("../assets/frames/weapon_arrow.png");

    std::vector<Projectile> projectileList;
    Projectile projectile;

    bool collision = false;

    void draw();
    void update(Rectangle playerRect, Vector2 mousePos, std::vector<Enemy::enemyStats>& enemies);
    
};

#endif