#ifndef THREADUTILS_H
#define THREADUTILS_H

#include <thread>
#include <iostream>

class ThreadGuard{
    private:
        std::thread& t; 
    public:
        explicit ThreadGuard(std::thread& _t) try : t(_t){}
        catch(...){
            std::cout<<"Exception caught in ThreadGuard constructor"<<std::endl;
        }
        ~ThreadGuard(){
            if(t.joinable()){
                try{
                    t.join();
                }
                catch(...){
                    std::cout<<"Exception caught in ThreadGuard destructor"<<std::endl;
                }
            }
        }

        ThreadGuard(const ThreadGuard&) = delete; 
        ThreadGuard& operator = (const ThreadGuard&) = delete; 

        ThreadGuard(ThreadGuard&& other) noexcept : t(other.t){}
        ThreadGuard& operator = (ThreadGuard&& other) {
            if(this!=&other){
                t = std::move(other.t); 
            }
            return *this; 
        }
};

#endif