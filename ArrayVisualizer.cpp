#include "ArrayVisualizer.h"
#include "need.h"
#include <iomanip>
#include <iostream>
using namespace std;

ArrayVisualizer::ArrayVisualizer() : values {10, 20, 30} {}

void ArrayVisualizer::display() const {
    cout << "\nArray /Vector State (size = " << values.size() <<
    ", capacity = " << values.capacity() << "):\n";

    if(values.empty()){
        cout << "[ empty ]\n";
        return;
    }
    cout << "Index: ";
    for(size_t i =0; i < values.size(); i++){
        cout << " [" << i << "] ";
    }
    cout << "\nValue: ";
    for(size_t i = 0; i < values.size(); i++){
        cout << " " << " " << std::setw(4) << values[i] << " ";
    }
    cout << "\n";
}

