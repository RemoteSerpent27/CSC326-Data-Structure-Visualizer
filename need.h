#ifndef need.h
#define need.h

#include <iostream>
#include <string>
#include <limits>

namespace need{
    inline int getValidInt(const std::string& prompt, int minVal, int maxVal){
        int value;
        while (true) {
            std::cout << prompt;
            if(std::cin >> value){
              if(std::cin.peek() = '\n' || std::cin.peek() == EOF)  //checks if theres extra characters
              {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if(value >= minVal && value <= maxVal){
                    return value;
                }
                std::cout << "[ERROR] Please enter a number betweem " 
                            <<minVal << " and " << maxVal << ".\n";
              }else{
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "[ERROR] Invalid input, whole numbers only \n";
              }
              } else{
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "[ERROR] Invalid inputm enter a valid integer \n";
              }  
            }
        }
    }


#endif need.h