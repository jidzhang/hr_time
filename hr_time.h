#ifndef HR_TIME_H
#define HR_TIME_H

#ifdef WIN32
#define OS_WIN
#elif WIN64
#define OS_WIN
#elif _MSC_VER
#define OS_WIN
#endif

#ifdef OS_WIN
#include <Windows.h>
struct StopWatch
{
    LARGE_INTEGER start;
    LARGE_INTEGER stop;
};
#else
#include <sys/time.h>
struct StopWatch
{
    timeval start;
    timeval stop;
};
#endif

class CStopWatch
{
public:
    CStopWatch();
    void startTimer();
    void stopTimer();
    double getElapsedTime();
private:
    StopWatch timer_;
#ifdef OS_WIN
    LARGE_INTEGER frequency_;
    double ToSeconds(const LARGE_INTEGER &v);
#endif
};

#include "hr_time_impl.h"

#endif
