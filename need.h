#ifndef need.h
#define need.h

#include <iostream>
#include <string>
#include <limits>

namespace need{
    inline int getValidInt(const std::string& prompt, int minVal, int MaxVal){
        int value;
        while (true) {
            std::cout << prompt;
            if(std:: cin >> value){
                
            }
        }
    }
}

#endif need.h