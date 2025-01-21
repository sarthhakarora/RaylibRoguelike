#include "enemy.h"
#include "raylib.h"
#include "raymath.h"
#include <ctime>
#include <iostream>

Enemy::Enemy()
{
    srand(time(0));
}

void Enemy::draw(Vector2 playerRect)
{
    for (size_t i = 0; i < enemies.size(); i++)
    {
        enemies[i].direction = Vector2Subtract(Vector2{playerRect.x, playerRect.y}, Vector2{enemies[i].dest.x, enemies[i].dest.y});
        if (Vector2Length(enemies[i].direction) > 0) {
            enemies[i].direction = Vector2Normalize(enemies[i].direction);
        }
        else {
            enemies[i].direction = {0, 0};
        }
        enemies[i].velocity = Vector2Scale(enemies[i].direction, enemies[i].speed);

        enemies[i].dest.x += enemies[i].velocity.x;
        enemies[i].dest.y += enemies[i].velocity.y;

        DrawTexturePro(
            enemies[i].texture,
            enemies[i].src,
            enemies[i].dest,
            Vector2{enemies[i].width / 2, enemies[i].height / 2},
            enemies[i].angle,
            WHITE);

        // std::cout << playerRect.x << " : " << playerRect.y << std::endl;
    }
}

void Enemy::spawn(Vector2 playerRect)
{
    for (size_t i = enemies.size(); i < MAXENEMYCOUNT; i++)
    {
        deathCube.width = 30;
        deathCube.height = 33;
        deathCube.speed = rand() % 4 + 3;
        deathCube.angle = 0.0f;
        deathCube.src = {0, 0, 10, 11};
        deathCube.dest = {0, 0, deathCube.width, deathCube.height};

        int spawnMargin = 300;
        int edge = rand() % 4;
        switch (edge)
        {
        case 0:
            // Above the player
            deathCube.dest.x = rand() % 1200 + playerRect.x - 600;  
            deathCube.dest.y = -rand() % spawnMargin - 330;
            break;
        case 1:
            // Below the player
            deathCube.dest.x = rand() % 1200 + playerRect.x - 600;  
            deathCube.dest.y = rand() % spawnMargin + 330;
            break;
        case 2:
            // To the right of the player
            deathCube.dest.x = rand() % spawnMargin + 430;
            deathCube.dest.y = rand() % 1200 + playerRect.y - 600;  
            break;
        case 3:
            // To the left of the player
            deathCube.dest.x = -rand() % spawnMargin - 430;
            deathCube.dest.y = rand() % 1200 + playerRect.y - 600; 
            break;
        }

        deathCube.texture = deathCubeTexture;
        deathCube.direction = Vector2Normalize(Vector2Subtract(Vector2{playerRect.x, playerRect.y}, Vector2{deathCube.dest.x, deathCube.dest.y}));
        deathCube.velocity = Vector2Scale(deathCube.direction, deathCube.speed);

        enemies.push_back(deathCube);

    }
}
