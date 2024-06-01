#ifndef THREADUTILS_H
#define THREADUTILS_H

#include <thread>
#include <iostream>

class ThreadGuard{
    private:
        std::thread& t; 
    public:
        explicit ThreadGuard(std::thread& _t) try : t(_t){std::cout<<"constructor called"<<std::endl;}
        catch(...){
            std::cout<<"Exception caught in ThreadGuard constructor"<<std::endl;
        }
        ~ThreadGuard(){
            std::cout<<"Destructor called"<<std::endl;
            if(t.joinable()){
                std::cout<<"Thread ID "<<t.get_id()<<std::endl; 
                std::cout<<"Thread joinable"<<std::endl;
                try{
                    t.join();
                }
                catch(...){
                    std::cout<<"Exception caught in ThreadGuard destructor"<<std::endl;
                    // Print what exception was caught
                    // std::cout<<e.what()<<std::endl;
                }
                std::cout<<"Thread joined"<<std::endl;
            }
            std::cout<<"ThreadGuard object destroyed"<<std::endl;
        }

        ThreadGuard(const ThreadGuard&) = delete; 
        ThreadGuard& operator = (const ThreadGuard&) = delete; 

        ThreadGuard(ThreadGuard&& other) noexcept : t(other.t){}
        ThreadGuard& operator = (ThreadGuard&& other) {
            std::cout<<"Move assignment operator called"<<std::endl;
            if(this!=&other){
                t = std::move(other.t); 
            }
            return *this; 
        }
};

#endif