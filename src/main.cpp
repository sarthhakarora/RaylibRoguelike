#include "raylib.h"
#include <vector>
#include "player.h"
#include "filereader.h"
#include "tilesystem.h"
#include "camera.h"
#include "weapon.h"
#include "enemy.h"
#include "score.h"
#include "startmenu.h"

int main() {
    struct Window {
        int height = 608;
        int width = 800;
        int fps = 60;
        bool gameActive = false;
        const char* title = "Rougelike game";

    } window;

    InitWindow(window.width, window.height, window.title);
    SetTargetFPS(window.fps);

    Player player;
    Filereader filereader;
    Tilesystem tilesystem;
    GameCam camera;
    Weapon weapon;
    Enemy enemy;
    Score score;
    Startmenu startmenu;
    
    camera.update();
    
    while (!WindowShouldClose()) {
        if (!window.gameActive) {
            BeginDrawing();
            ClearBackground(RAYWHITE);

            BeginDrawing();
            
            window.gameActive = startmenu.drawMenu(window.gameActive);

            std::cout << window.gameActive << std::endl;

            EndDrawing();
        }
        

        if (window.gameActive) {
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

            score.update(weapon.collision);
            score.draw();

            window.gameActive = player.healthUpdate(enemy.enemies, window.gameActive);
            player.healthDraw();
            
            DrawFPS(window.width - 90, window.height - 30);

            tilesystem.wallRects.clear(); 

            EndDrawing();

        }
    }
    CloseWindow();
    return 0;
}

