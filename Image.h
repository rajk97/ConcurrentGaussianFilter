#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <opencv2/opencv.hpp>


class Image{
    private:
        int width{0}; 
        int height{0}; 
        cv::Mat data;  
    
    public:
        Image(const std::string& fileName);
        Image(cv::Mat& image);
        void save(const std::string& fileName, cv::Mat& image) const;
        void display(const std::string& windowName, cv::Mat& image) const;
        int getWidth() const; 
        int getHeight() const; 
        cv::Mat& getData();  
        ~Image();
};

#endif