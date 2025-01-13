#ifndef CAMERA_H
#define CAMERA_h

#include "raylib.h"
#include <vector>

class GameCam {
public:
    // GameCam(Vector2 camTarget);

    Camera2D camera = { 0 };
    Vector2 target = { 0, 0 };

    void update();
};

#endif