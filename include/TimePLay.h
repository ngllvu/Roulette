#pragma once
#include "include.h"
#include "Roulette.h"

class TimePlay
{
private:
    clock_t start, end, pauseEnd, pauseStart;
    double pause = 0;
    double timePlay = 0;
    friend class Roulette;

public:
    TimePlay();
    ~TimePlay();
    void StartGame();
    void StartPause();
    void EndPause();
    void EndGame();
};