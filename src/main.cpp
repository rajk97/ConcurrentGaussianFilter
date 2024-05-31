#ifdef ENABLE_TRACY_PROFILING
 #define TRACY_ENABLE
 #include "Tracy.hpp"
 #define MY_PROFILE_SCOPE ZoneScoped
#else
 #define MY_PROFILE_SCOPE
#endif


#include <pthread.h>
#include <sched.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <yaml-cpp/yaml.h>

#include "Image.h"
#include "GaussianBlur.h"


int main(){

    const std::string filePath = "../data/dhoni.jpg";
    Image image(filePath);
    cv::Mat img = image.getData();
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    cv::Mat blurredImage;
    // Multithreaded version 
    cv::Mat blurredImageMT;
    GaussianBlur gb;
    blurredImage = gb.applyGaussianBlur(gray, 51, 5.0);
    blurredImageMT = gb.applyGaussianBlurMT(gray, 51, 5.0);
    Image blurredImageObj(blurredImageMT);
    blurredImageObj.save("data/blurredImage.jpg", blurredImageMT);
    blurredImageObj.display("Blurred Image", blurredImageMT);
    return 0;
}