#include <iostream>
#include "osm.h"
#include <sys/time.h>
#include <time.h>

double get_res(timeval begin, timeval end, unsigned int  iterations){
    return (double(((end.tv_sec - begin.tv_sec)*1000000+(end.tv_usec - begin.tv_usec))*1000))/double(5*iterations);
}

double osm_operation_time(unsigned int iterations)
{
    struct timeval begin, end;
    if (gettimeofday(&begin, nullptr) == -1 || iterations == -1){
        return -1;
    }
    int x;
    for (int i = 0; i < iterations; i ++){
        x = i + i;
        x = i + i;
        x = i + i;
        x = i + i;
        x = i + i;
    }
    if(gettimeofday(&end, nullptr) == -1){
        return -1;
    }
    return get_res(begin,end,iterations);
}

void func(){
    return;
}

/* Time measurement function for an empty function call.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_function_time(unsigned int iterations){
    struct timeval begin, end;
    if (gettimeofday(&begin, nullptr) == -1 || iterations == -1){
        return -1;
    }
    for (int i = 0; i < iterations; i ++){
        func();
        func();
        func();
        func();
        func();
    }
    if(gettimeofday(&end, nullptr) == -1){
        return -1;
    }
    return get_res(begin, end, iterations);
}

/* Time measurement function for an empty trap into the operating system.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_syscall_time(unsigned int iterations){
    struct timeval begin{}, end{};
    if (gettimeofday(&begin, nullptr) == -1 || iterations == -1){
        return -1;
    }
    for(int i = 0; i < iterations; i ++){
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
    }
    if(gettimeofday(&end, nullptr) == -1){
        return -1;
    }
    return get_res(begin, end, iterations);
}
