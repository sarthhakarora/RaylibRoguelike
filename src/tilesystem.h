#ifndef TILESYSTEM_H
#define TILESYSTEM_H

#include <vector>
#include "filereader.h"
#include "raylib.h"

class Tilesystem {
public:
    Filereader filereader;

    std::vector<std::vector<int>> tileMap = filereader.loadCsv("../assets/map/map.csv");

    // wall Textures
    Texture2D wall = LoadTexture("../assets/world/sprite_013.png");
    
    // floor Textures
    Texture2D floor = LoadTexture("../assets/world/sprite_03.png");
    Texture2D VlowCrackFloor = LoadTexture("../assets/world/sprite_56.png");
    Texture2D lowCrackFloor = LoadTexture("../assets/world/sprite_03.png");
    Texture2D midCrackFloor = LoadTexture("../assets/world/sprite_01.png");
    Texture2D hole1Floor = LoadTexture("../assets/world/sprite_58.png");
    Texture2D hole2Floor = LoadTexture("../assets/world/sprite_59.png");
    Texture2D hole3Floor = LoadTexture("../assets/world/sprite_63.png");
    Texture2D spike = LoadTexture("../assets/world/sprite_72.png");
    
    Rectangle src;
    Rectangle dest;

    std::vector<Rectangle> wallRects;
    std::vector<Rectangle> killRects; // I cant think of a better name it is just the tile that kills player

    Texture2D tileTextures[10] {
        wall,
        VlowCrackFloor,
        lowCrackFloor,
        midCrackFloor,
        VlowCrackFloor,
        floor,
        spike
    };



    Tilesystem();
    void drawMap(Rectangle playerRect);
    std::vector<Rectangle> hitList;
    // void updateMap();
};

#endif 