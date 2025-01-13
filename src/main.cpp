#include "raylib.h"
#include <vector>
#include "player.h"
#include "filereader.h"
#include "tilesystem.h"
#include "camera.h"
#include "weapon.h"
#include "enemy.h"
#include "score.h"

int main() {
    InitWindow(800, 608, "Rougelike game");
    SetTargetFPS(60);

    Player player;
    Filereader filereader;
    Tilesystem tilesystem;
    GameCam camera;
    Weapon weapon;
    Enemy enemy;
    Score score;

    camera.update();
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        
        camera.camera.target = Vector2{player.player.dest.x, player.player.dest.y};
        
        BeginMode2D(camera.camera);
        
        tilesystem.drawMap(player.player.dest);
        
        player.update(camera.camera, tilesystem.wallRects);
        player.draw();

        enemy.spawn(Vector2{player.player.dest.x, player.player.dest.y});
        enemy.draw(Vector2{player.player.dest.x, player.player.dest.y});

        weapon.update(player.player.dest, GetScreenToWorld2D(GetMousePosition(), camera.camera), enemy.enemies);
        weapon.draw();

        EndMode2D();

        score.draw();
        DrawFPS(20, 60);
        
        tilesystem.wallRects.clear(); 

        EndDrawing();

    }

    CloseWindow();
    return 0;
}

