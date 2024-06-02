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

    auto normalStart = std::chrono::steady_clock::now();
    blurredImage = gb.applyGaussianBlur(gray, 51, 5.0);
    auto normalEnd = std::chrono::steady_clock::now();
    auto normalDuration = std::chrono::duration_cast<std::chrono::milliseconds>(normalEnd - normalStart);
    std::cout<<"Normal Gaussian Blur Time: "<<normalDuration.count()<<" ms"<<std::endl; 

    auto mtStart = std::chrono::steady_clock::now();
    blurredImageMT = gb.applyGaussianBlurMT(gray, 51, 5.0);
    auto mtEnd = std::chrono::steady_clock::now();
    auto mtDuration = std::chrono::duration_cast<std::chrono::milliseconds>(mtEnd - mtStart);
    std::cout<<"Multithreaded Gaussian Blur Time: "<<mtDuration.count()<<" ms"<<std::endl;
    
    Image blurredImageObj(blurredImageMT);
    blurredImageObj.save("data/blurredImage.jpg", blurredImageMT);
    blurredImageObj.display("Blurred Image", blurredImageMT);
    return 0;
}