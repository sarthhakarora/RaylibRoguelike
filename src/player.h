#ifndef PLAYER_H
#define PLAYER_H

#include "enemy.h"
#include "timer.h"

#include "raylib.h"
#include <vector>
#include <unordered_map>
#include <string>

class Player {
public:
    Player();

    struct playerStats {
        float height;
        float width;
        float speed;
        float playerInvincible;
        int health;
        int maxHealth;
        Color tint;
        Vector2 movement;
        Texture2D currentTexture;
        Texture2D textureRight;
        Texture2D textureLeft;
        Rectangle src;
        Rectangle dest;

    };

    struct Health
    {
        float height;
        float width;
        Texture2D fullHeartTexture;
        Texture2D emptyHeartTexture;
        Texture2D currentTexture;
        Rectangle src;
        Rectangle dest;

    };

    Texture2D fullHeartTexture = LoadTexture("../assets/frames/ui_heart_full.png");
    Texture2D emptyHeartTexture = LoadTexture("../assets/frames/ui_heart_empty.png");
    

    playerStats player;
    timerClass playerTimer;
    timerClass::timer timer;
    Health health;
    std::vector<Health> healthList;
    std::vector<Rectangle> hitList;

    void draw();
    void update(Camera2D cam, std::vector<Rectangle> rectList);
    void unload();
    void healthDraw();
    bool healthUpdate(std::vector<Enemy::enemyStats> &enemies, bool gameActive);

};

std::vector<Rectangle> checkCollision(Rectangle playerRect, std::vector<Rectangle>& rectList, Vector2 worldPlayerPos);

#endif