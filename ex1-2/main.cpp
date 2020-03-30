//
// Created by me on 30/03/2020.
//
#include <string>
#include <iostream>
#include "main.h"
#include "osm.h"

int main(int argc, char **argv){
    unsigned int iteration = std::stoi(argv[1]);
    double res1 = osm_operation_time(iteration);
    double res2 = osm_function_time(iteration);
    double res3 = osm_syscall_time(iteration);
    std::cout<<"operation time: "<<res1<<std::endl;
    std::cout<<"function time: "<<res2<<std::endl;
    std::cout<<"syscall time: "<<res3<<std::endl;
    return 0;
}
