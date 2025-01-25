#include "timer.h"
#include "raylib.h"

#include <iostream>

void timerClass::startTimer(timer *timer, float lifetime)
{
    if (timer != __null) {
        timer->lifetime = lifetime;
        timerState = true;

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
    if (timer != __null) {
        return timer->lifetime <= 0;

    } else {
        return false; 

    }
        
    
}
