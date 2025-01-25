#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include <vector>

class Enemy {
public:
    struct enemyStats
    {
        float width;
        float height;
        float speed;
        float angle;
        Texture2D texture;
        Vector2 direction;
        Vector2 velocity;
        Rectangle src;
        Rectangle dest;

    };
    
    Texture2D deathCubeTexture = LoadTexture("../assets/frames/deathCube.png");
    enemyStats deathCube;
    std::vector<enemyStats> enemies;
    int maxenemycount = 5;

    Enemy();
    void draw(Vector2 playerRect);
    void spawn(Vector2 playerRect, int score);
    
};

#endif