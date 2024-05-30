#ifndef GAUSSIANBLUR_H
#define GAUSSIANBLUR_H

#include <iostream>
#include <string>
#include<opencv2/opencv.hpp>

class GaussianBlur{
    private:
    public:
        
        GaussianBlur();
        
        cv::Mat applyGaussianBlur(cv::Mat& image, int kernelSize, double sigma);
        
        cv::Mat applyGaussianBlurMT(cv::Mat& image, int kernelSize, double sigma);
        
        void createGaussianKernel(int kernelSize, double sigma, std::vector<float>& kernel);

        void applyGaussianKernelX(cv::Mat& image, std::vector<float>& kernel, cv::Mat& blurredImage);

        void applyGaussianKernelY(cv::Mat& image, std::vector<float>& kernel, cv::Mat& blurredImage);

        void edgePaddingX(cv::Mat& image, std::vector<float>& kernel, cv::Mat& blurredImage);

        void edgePaddingY(cv::Mat& image, std::vector<float>& kernel, cv::Mat& blurredImage);

        ~GaussianBlur();
};

#endif 