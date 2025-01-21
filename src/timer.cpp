#include "timer.h"
#include "raylib.h"

void timerClass::startTimer(timer *timer, float lifetime)
{
    if (timer != __null) {
        timer->lifetime = lifetime;

    }

}


void timerClass::updateTimer(timer *timer)
{
    if (timer != __null && timer->lifetime > 0) {
        timer->lifetime -= GetFrameTime();

    }

}


bool timerClass::timerDone(timer *timer)
{
    if (timer != __null) 
        return timer->lifetime <= 0;

        return false;
    
    
}
