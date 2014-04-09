#ifndef HR_TIME_IMPL_H
#define HR_TIME_IMPL_H

#ifdef OS_WIN
CStopWatch::CStopWatch()
{
    timer_.start.QuadPart = 0;
    timer_.stop.QuadPart  = 0;
    QueryPerformanceFrequency(&frequency_);
}
void CStopWatch::startTimer()
{
    QueryPerformanceCounter(&timer_.start);
}
void CStopWatch::stopTimer()
{
    QueryPerformanceCounter(&timer_.stop);
}
double CStopWatch::getElapsedTime()
{
    LARGE_INTEGER time;
    time.QuadPart = timer_.stop.QuadPart - timer_.start.QuadPart;
    return ToSeconds(time);
}
double CStopWatch::ToSeconds(const LARGE_INTEGER &v)
{
    return ((double)v.QuadPart/(double)frequency_.QuadPart);
}
#else
CStopWatch::CStopWatch()
{}
void CStopWatch::startTimer()
{
    gettimeofday(&timer_.start, NULL);
}
void CStopWatch::stopTimer()
{
    gettimeofday(&timer_.stop, NULL);
}
double CStopWatch::getElapsedTime()
{
    timeval res;
    timersub(&timer_.stop, &timer_.start, &res);
    return res.tv_sec +  res.tv_usec/1000000.0;
}

#endif

#endif
