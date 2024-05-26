#include "Image.h"

Image::Image(const std::string& fileName){

    try{
        
        if(fileName.empty()){
            throw std::runtime_error("File name is empty");
        }

        data = cv::imread(fileName, cv::IMREAD_COLOR);
        
        
        if(data.empty()){
            throw std::runtime_error("Image didn't load");
        }

        width = data.cols; 
        height = data.rows;
    }
    catch(...){
        throw std::runtime_error("Image didn't load");
    }
}

Image::Image(cv::Mat& image){

    try{
        if(image.empty()){
            throw std::runtime_error("Image is empty");
        }
        data = image.clone();
        width = data.cols; 
        height = data.rows;
    }
    catch(...){
        throw std::runtime_error("Image is empty");
    }
    return; 
}

void Image::save(const std::string& fileName, cv::Mat& image) const{
    try{
        cv::imwrite(fileName, image);
    }
    catch(...){
        throw std::runtime_error("Image didn't save");
    }
}

void Image::display(const std::string& windowName, cv::Mat& image) const{
    try{
        cv::namedWindow(windowName, cv::WINDOW_AUTOSIZE);
        cv::imshow(windowName, image);
        cv::waitKey(0);
        cv::destroyWindow(windowName);
    }
    catch(...){
        return; 
    }
}

int Image::getWidth() const{
    return data.cols; 
}

int Image::getHeight() const{
    return data.rows; 
}

cv::Mat& Image::getData(){
    return data; 
}

Image::~Image(){
    // Delete the image data
    data.release();
    return;
 
}

