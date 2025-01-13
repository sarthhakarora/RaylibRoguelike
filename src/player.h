#ifndef PLAYER_H
#define PLAYER_H

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
        Vector2 movement;
        Texture2D currentTexture;
        Texture2D textureRight;
        Texture2D textureLeft;
        Texture2D textureUp;
        Texture2D textureDown;
        Rectangle src;
        Rectangle dest;
    };


    playerStats player;
    std::vector<Rectangle> hitList;

    void draw();
    void update(Camera2D cam, std::vector<Rectangle> rectList);
    void unload();
};

std::vector<Rectangle> checkCollision(Rectangle playerRect, std::vector<Rectangle>& rectList, Vector2 worldPlayerPos);

#endif