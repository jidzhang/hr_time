//compile:
//  g++ demo.cpp
//or
//  cl /GX demo.cpp

#include "hr_time.h"
#include <iostream>
#include <cmath>
int main()
{
    CStopWatch timer;
    timer.startTimer();
    for (unsigned int i=0; i<1000000; ++i) {
        sqrt((double)i);
    }
    timer.stopTimer();
    std::cout << timer.getElapsedTime() << std::endl;
    return 0;
}
