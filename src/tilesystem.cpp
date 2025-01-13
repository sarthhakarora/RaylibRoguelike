#include "tilesystem.h"
#include "filereader.h"
#include "raylib.h"
#include <vector>
#include <iostream>

Tilesystem::Tilesystem()
{
    src = {0, 0, 16, 16};
    dest = {0, 0, 48, 48};
}

void Tilesystem::drawMap(Rectangle playerRect)
{
    for (size_t i = 0; i <= tileMap.size() - 1; i++) {
        for (size_t j = 0; j <= tileMap[i].size() - 1; j++) {
            DrawTexturePro(tileTextures[tileMap[i][j]], src, {i * 48.0f - 1600, j * 48.0f - 1600, 48, 48}, Vector2{16, 16}, 0.0f, WHITE);

            switch (tileMap[i][j])
            {
            case 0:
                wallRects.push_back({i * 48.0f - 1600, j * 48.0f - 1600, 48, 48});
                break;
            
            case 1:
                killRects.push_back({i * 48.0f - 1600, j * 48.0f - 1600, 48, 48});
                break;

            default:
                break;
            }
        }        
    }

}

// void Tilesystem::updateMap()
// {
// }
