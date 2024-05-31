#ifndef THREADUTILS_H
#define THREADUTILS_H

#include <thread>
#include <iostream>

class ThreadGuard{
    private:
        std::thread& t; 
    public:
        explicit ThreadGuard(std::thread& _t): t(_t){}
        ~ThreadGuard(){
            if(t.joinable()){
                t.join();
            }
        }

        ThreadGuard(const ThreadGuard&) = delete; 
        ThreadGuard& operator = (const ThreadGuard&) = delete; 

        ThreadGuard(ThreadGuard&& other) noexcept : t(other.t){}
        ThreadGuard& operator = (ThreadGuard&& other) noexcept{
            if(this!=&other){
                t = std::move(other.t); 
            }
            return *this; 
        }
};

#endif