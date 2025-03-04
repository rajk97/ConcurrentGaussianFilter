#include "GaussianBlur.h"
#include "ThreadUtils.h"
// #include "Tracy.hpp"

GaussianBlur::GaussianBlur(){

}

GaussianBlur::~GaussianBlur(){

}

void GaussianBlur::createGaussianKernel(int kernelSize, double sigma, std::vector<float>& kernel){

    ZoneScopedN("Create Gaussian Kernel");

    try{
        if(kernelSize%2==0){
            throw std::runtime_error("Kernel size must be odd");
        }
        else if(kernelSize<3){
            throw std::runtime_error("Kernel size must be at least 3");
        }
        else if(sigma<=0){
            throw std::runtime_error("Sigma must be greater than 0");
        }

        double sum{0.0};

        int size = kernelSize/2; 

        for(int i=-size; i<=size; i++){
            kernel[i+size] = std::exp((-1.0*i*i)/(2.0*sigma*sigma))/(std::sqrt(2.0*M_PI)*sigma); 
            sum += kernel[i+size];
        }

        // Normalize the kernel 
        for(int i=0; i<kernelSize; i++){
            kernel[i]/=sum; 

        }

    }
    catch(...){
        throw std::runtime_error("Error creating Gaussian Kernel");
    }
}
void GaussianBlur::applyGaussianKernelX(const cv::Mat& image, const std::vector<float>& kernel, cv::Mat& blurredImage){

    ZoneScopedN("Apply Gaussian Kernel in X direction");

    try{
        
        int kernelSize = kernel.size(); 
        int size = kernelSize/2; 

        if(image.empty()){
            throw std::runtime_error("Image is empty");
        }

        int rows = image.rows; 
        int cols = image.cols;

        if(kernelSize>cols){
            throw std::runtime_error("Kernel size is greater than image width");
        }
        if(kernelSize>rows){
            throw std::runtime_error("Kernel size is greater than image height");
        }

        for(int i=size; i<rows - size; i++){
            for(int j=size; j<cols-size; j++){
                float sum{0.0}; 
                for(int k=-size; k<=size; k++){
                    sum+=kernel[size+k]*image.at<uchar>(i, j+k);
                }
                blurredImage.at<uchar>(i, j) = cv::saturate_cast<uchar>(sum);
            }
        }
    }
    catch(...){
        throw std::runtime_error("Error applying Gaussian Kernel in x direction");
    }

    return; 

}

void GaussianBlur::applyGaussianKernelXMT(const cv::Mat& image, const std::vector<float>& kernel, cv::Mat& blurredImage, const int startRow, const int endRow){

    ZoneScopedN("MULTI Apply Gaussian Kernel in X direction");

    try{
        
        int kernelSize = kernel.size(); 
        int size = kernelSize/2; 

        if(image.empty()){
            throw std::runtime_error("Image is empty");
        }

        int rows = image.rows; 
        int cols = image.cols;

        if(kernelSize>cols){
            throw std::runtime_error("Kernel size is greater than image width");
        }
        if(kernelSize>rows){
            throw std::runtime_error("Kernel size is greater than image height");
        }

        for(int i=startRow; i<endRow; i++){
            for(int j=size; j<cols-size; j++){
                float sum{0.0}; 
                
                for(int k=-size; k<=size; k++){
                    sum+=kernel[size+k]*image.at<uchar>(i, j+k);
                }
                blurredImage.at<uchar>(i, j) = cv::saturate_cast<uchar>(sum);
            }
        }
    }
    catch(...){
        throw std::runtime_error("Error applying Gaussian Kernel in x direction");
    }

    return; 

}


void GaussianBlur::applyGaussianKernelY(const cv::Mat& image, const std::vector<float>& kernel, cv::Mat& blurredImage){

    ZoneScopedN("Apply Gaussian Kernel in Y direction");

    try{
        
        int kernelSize = kernel.size(); 
        int size = kernelSize/2; 

        if(image.empty()){
            throw std::runtime_error("Image is empty");
        }

        int rows = image.rows; 
        int cols = image.cols;

        if(kernelSize>cols){
            throw std::runtime_error("Kernel size is greater than image width");
        }
        if(kernelSize>rows){
            throw std::runtime_error("Kernel size is greater than image height");
        }

        for(int i=size; i<rows - size; i++){
            for(int j=size; j<cols-size; j++){
                float sum{0.0}; 
                for(int k=-size; k<=size; k++){
                    sum+=kernel[size+k]*image.at<uchar>(i+k, j);
                }
                blurredImage.at<uchar>(i, j) = cv::saturate_cast<uchar>(sum);
            }
        }
    }
    catch(...){
        throw std::runtime_error("Error applying Gaussian Kernel in y direction");
    }

    return; 

}

void GaussianBlur::edgePaddingX(cv::Mat& image, std::vector<float>& kernel, cv::Mat& blurredImage){

    ZoneScopedN("Edge Padding in X direction");

    try{

        if(image.empty()){
            throw std::runtime_error("Image is empty");
        }

        if(kernel.size()%2==0){
            throw std::runtime_error("Kernel size must be odd");
        }

        if(kernel.size()<3){
            throw std::runtime_error("Kernel size must be at least 3");
        }

        if(kernel.size()>image.cols){
            throw std::runtime_error("Kernel size is greater than image width");
        }

        int kernelSize = kernel.size();
        int size = kernelSize/2;

        int rows = image.rows; 
        int cols = image.cols;

        for(int i=0; i<rows; i++){
            for(int j=0; j<size; j++){
                float sum{0.0};
                for(int k=-j; k<=size; k++)
                    sum+=kernel[size+k]*image.at<uchar>(i, j+k);
                blurredImage.at<uchar>(i, j) = cv::saturate_cast<uchar>(sum);
            }
            for(int j=cols-size; j<cols; j++){
                float sum{0.0};
                for(int k=-size; k<=cols-j; k++)
                    sum+=kernel[size+k]*image.at<uchar>(i, j+k);
                blurredImage.at<uchar>(i, j) = cv::saturate_cast<uchar>(sum);
            }
        }
    }
    catch(...){
        throw std::runtime_error("Error padding edges in x direction");
    }

    return; 
}

void GaussianBlur::edgePaddingY(cv::Mat& image, std::vector<float>& kernel, cv::Mat& blurredImage){

    ZoneScopedN("Edge Padding in Y direction");

    try{

        if(image.empty()){
            throw std::runtime_error("Image is empty");
        }

        if(kernel.size()%2==0){
            throw std::runtime_error("Kernel size must be odd");
        }

        if(kernel.size()<3){
            throw std::runtime_error("Kernel size must be at least 3");
        }

        if(kernel.size()>image.rows){
            throw std::runtime_error("Kernel size is greater than image height");
        }

        int kernelSize = kernel.size();
        int size = kernelSize/2;

        int rows = image.rows; 
        int cols = image.cols;

        for(int i=0; i<cols; i++){
            for(int j=0; j<size; j++){
                float sum{0.0};
                for(int k=-j; k<=size; k++)
                    sum+=kernel[size+k]*image.at<uchar>(j+k, i);
                blurredImage.at<uchar>(j, i) = cv::saturate_cast<uchar>(sum);
            }
            for(int j=rows-size; j<rows; j++){
                float sum{0.0};
                for(int k=-size; k<=rows-j; k++)
                    sum+=kernel[size+k]*image.at<uchar>(j+k, i);
                blurredImage.at<uchar>(j, i) = cv::saturate_cast<uchar>(sum);
            }
        }
    }
    catch(...){
        throw std::runtime_error("Error padding edges in y direction");
    }

    return; 
}

cv::Mat GaussianBlur::applyGaussianBlur(cv::Mat& image, int kernelSize, double sigma){
    
    ZoneScopedN("Normal Apply Gaussian Blur");

    cv::Mat blurredImage(image.size(), image.type()); 

    std::vector<float> kernel(kernelSize, 0.0); 
    
    createGaussianKernel(kernelSize, sigma, kernel);

    // Do convolution in x direction 
    applyGaussianKernelX(image, kernel, blurredImage);
    // edgePaddingX(image, kernel, blurredImage);

    // // Do convolution in y direction 
    // applyGaussianKernelY(image, kernel, blurredImage);
    // edgePaddingY(image, kernel, blurredImage);

    // Take care of the edge padding 

    // Return the blurred image 
    return blurredImage; 
}

cv::Mat GaussianBlur::applyGaussianBlurMT(cv::Mat& image, int kernelSize, double sigma){
    
    ZoneScopedN("Multithreaded Apply Gaussian Blur");

    cv::Mat blurredImage(image.size(), image.type()); 

    std::vector<float> kernel(kernelSize, 0.0); 

    
    createGaussianKernel(kernelSize, sigma, kernel);

    int nThreads = std::thread::hardware_concurrency()-1; 
    if(nThreads<=1){
        nThreads = 1; 
    }
    else{
        nThreads -= 1;
    }

    std::cout<<"Number of threads: "<<nThreads<<std::endl;

    int rows = image.rows; 
    
    int rowsPerThread = rows/nThreads; 
    int remainingRows = rows%nThreads; 

    std::vector<std::thread> threads; 
    // std::vector<ThreadGuard> threadGuards;
    std::vector<std::unique_ptr<ThreadGuard>> threadGuards;  
    int currentRow{0};

    threads.reserve(nThreads);
    threadGuards.reserve(nThreads);

    try{

        for(int i=0; i<nThreads; i++){

            int startRow = currentRow; 
            int endRow = currentRow + rowsPerThread + (i<remainingRows?1:0);

            threads.emplace_back(&GaussianBlur::applyGaussianKernelXMT, this, std::ref(image), std::ref(kernel), std::ref(blurredImage), startRow, endRow);
            threadGuards.emplace_back(std::make_unique<ThreadGuard>(threads.back()));
            currentRow = endRow;
            startRow = endRow;
        }

    }

    catch(const std::exception& e){
        std::cerr<<"std exception: "<<e.what()<<std::endl; 
    }

    catch(...){
        // print what went wrong
        std::cerr<<"Unknown exception"<<std::endl;
        throw;
    }

    // Return the blurred image 
    return blurredImage; 
}
