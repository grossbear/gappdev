//#include <iostream>
//#include <chrono>
//#include <thread>
//#include <cmath>
//#include <ctime>

#include <stdio.h>
#include <cmath>
#include "Base/Utils/Timer/Timer.h"

int main()
{
    CStopWatch timer;
    timer.Start();
    fprintf(stderr, "start timer\n");
    
    for(unsigned i=0; i < 1000; i++) {
        double res = sin((double)i);
    }
    
    timer.Pause();
    float dtime = timer.GetTime();
    fprintf(stderr, "time passed: %f\n",dtime);
    
    unsigned int ticks = timer.GetTicks();
    fprintf(stderr, "ticks: %d\n",ticks);

    return 0;
    /*
    volatile unsigned sink = 0;
    clock_t tick1 = clock();
    
    for(unsigned i=0; i < 1000; i++) {
        double res = sin((double)i);
    }
    //std::this_thread::sleep_for (std::chrono::seconds(1));
   
    clock_t tick2 = clock();
    
    double dtime = ((double)(tick2 - tick1))  / CLOCKS_PER_SEC;
    
    std::cout << "tick1 = " << tick1 << std::endl;
    std::cout << "tick2 = " << tick2 << std::endl;
    std::cout << "time = " << dtime << std::endl;
    std::cout << "CLOCK_PER_SEC = " << CLOCKS_PER_SEC << std::endl;
    
    std::cout << "cpluplus version = " << __cplusplus << std::endl;
    */
    
    /*
    typedef std::chrono::high_resolution_clock Time;
    //std::chrono::milliseconds ms;
    //std::chrono::duration<float> fsec;
    clock_t ticks1 = clock();
    std::cout << "ticks1 = " << (double)ticks1 << std::endl;

    timespec ts1, ts2;
    clock_gettime(CLOCK_REALTIME, &ts1);


    std::chrono::high_resolution_clock::time_point time1 = Time::now();

    //some calculation
    for(int i = 0; i < 1000; i++){
        double sinval = sin(double(i)/0.1);
        //std::cout << "sinvalue = " << sinval << std::endl;
    }

    std::chrono::high_resolution_clock::time_point time2 = Time::now();
    std::chrono::duration<float> fsec = time2 - time1;

    std::chrono::milliseconds dsec = std::chrono::duration_cast<std::chrono::milliseconds>(fsec);
    std::cout << fsec.count() << " s\n";
    std::cout << dsec.count() << " ms\n";

    clock_t ticks2 = clock();
    std::cout << "ticks1 = " << (double)ticks1 << std::endl;
    std::cout << "ticks2 = " << (double)ticks2 << std::endl;

    double ticksdiff = (double) (ticks2 - ticks1) / CLOCKS_PER_SEC;
    std::cout << "tm diff = " << ticksdiff << std::endl;
    std::cout << "clocks per sec = " << CLOCKS_PER_SEC << std::endl;

    clock_gettime(CLOCK_REALTIME, &ts2);
    long tsdiff = (long)(ts2.tv_sec - ts1.tv_sec);
    long long ldiff = ts2.tv_nsec - ts1.tv_nsec;

    std::cout << "tsdiff = " << tsdiff << std::endl;
    std::cout << "ldiff = " << ldiff << std::endl;    
    */
}
