#include "Timer.h"

using namespace std;
using namespace std::chrono;

Timer::Timer()
{
    start();
}

void Timer::start()
{
    startTime = high_resolution_clock::now();
}

long long Timer::elapsed() const
{
    auto endTime = high_resolution_clock::now();
    return duration_cast<microseconds>(endTime - startTime).count();
}
