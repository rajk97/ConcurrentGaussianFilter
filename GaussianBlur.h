#ifndef GAUSSIANBLUR_H
#define GAUSSIANBLUR_H

#include <iostream>
#include <string>
#include<opencv2/opencv.hpp>
#include <vector>
#include <memory>

#ifdef ENABLE_TRACY_PROFILING
 #include "Tracy.hpp"
 #define MY_PROFILE_SCOPE ZoneScoped
#else
 #define MY_PROFILE_SCOPE
#endif

class GaussianBlur{
    private:
    public:
        
        GaussianBlur();
        
        cv::Mat applyGaussianBlur(cv::Mat& image, int kernelSize, double sigma);
        
        cv::Mat applyGaussianBlurMT(cv::Mat& image, int kernelSize, double sigma);
        
        void createGaussianKernel(int kernelSize, double sigma, std::vector<float>& kernel);

        void applyGaussianKernelX(const cv::Mat& image, const std::vector<float>& kernel, cv::Mat& blurredImage);

        void applyGaussianKernelY(const cv::Mat& image, const std::vector<float>& kernel, cv::Mat& blurredImage);

        void edgePaddingX(cv::Mat& image, std::vector<float>& kernel, cv::Mat& blurredImage);

        void edgePaddingY(cv::Mat& image, std::vector<float>& kernel, cv::Mat& blurredImage);

        void applyGaussianKernelXMT(const cv::Mat& image, const std::vector<float>& kernel, cv::Mat& blurredImage, const int startRow, const int endRow);

        ~GaussianBlur();
};

#endif 