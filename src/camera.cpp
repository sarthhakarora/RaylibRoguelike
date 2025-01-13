#include "camera.h"

// GameCam::GameCam(Vector2 camTarget) {
//     target = camTarget;
// }

void GameCam::update()
{
    camera.target = target;
    camera.offset = Vector2{400, 304};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    
}
