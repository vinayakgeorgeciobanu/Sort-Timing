#ifndef TIMER_H
#define TIMER_H

#include <chrono>

using namespace std;
using namespace std::chrono;

class Timer
{
private:
    time_point<high_resolution_clock> startTime;

public:
    Timer();
    void start();
    long long elapsed() const;
};

#endif