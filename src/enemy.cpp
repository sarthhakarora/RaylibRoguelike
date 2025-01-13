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
        if (Vector2Length(enemies[i].direction) > 0)
        {
            enemies[i].direction = Vector2Normalize(enemies[i].direction);
        }
        else
        {
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

        int spawnMargin = 100;
        int edge = rand() % 4;
        switch (edge)
        {
        case 0:
            deathCube.dest.x = rand() % 400 + playerRect.x;
            deathCube.dest.y = -spawnMargin;
            break;
        case 1:
            deathCube.dest.x = rand() % 400 - playerRect.x;
            deathCube.dest.y = 600 + spawnMargin;
            break;
        case 2:
            deathCube.dest.x = -spawnMargin;
            deathCube.dest.y = rand() % 300 + playerRect.y;
            break;
        case 3:
            deathCube.dest.x = 800 + spawnMargin;
            deathCube.dest.y = rand() % 300 + playerRect.y;
            break;
        }

        deathCube.texture = deathCubeTexture;
        deathCube.direction = Vector2Normalize(Vector2Subtract(Vector2{playerRect.x, playerRect.y}, Vector2{deathCube.dest.x, deathCube.dest.y}));
        deathCube.velocity = Vector2Scale(deathCube.direction, deathCube.speed);

        enemies.push_back(deathCube);
    }
}
