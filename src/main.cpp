#ifdef ENABLE_TRACY_PROFILING
 #define TRACY_ENABLE
 #include "Tracy.hpp"
 #define MY_PROFILE_SCOPE ZoneScoped
#else
 #define MY_PROFILE_SCOPE
#endif

#define _GNU_SOURCE 

#include <pthreah.h>
#include <sched.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <yaml-cpp/yaml.h>

int main(){
    std::cout<<"Hello World\n";
    return 0;
}