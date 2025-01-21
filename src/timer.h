#ifndef TIMER_H
#define TIMER_H

class timerClass {
public:
    typedef struct
    {
        float lifetime;
    }timer;

    void startTimer(timer* timer, float lifetime);
    void updateTimer(timer* timer);
    bool timerDone(timer* timer);
};

#endif