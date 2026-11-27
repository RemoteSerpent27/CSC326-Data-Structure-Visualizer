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

void ArrayVisualizer::accessAt(int index) const{
    if (values.empty()){
        cout << "\n[Underflow Error] Array is empty. No element to access.\n";
        return;
    }
    if(index < 0 || index >= static_cast<int>(values.size())){
        cout << "\n[Bounds Error] Valid indexes are 0 through ";
        return;
    }
    cout << "\nDirect Access at Index[" << index << "] -> Value: " << values.size() - 1 << ".\n";
    cout << "Time Complexity: O(1) | Auxiliary Space: O(1)\n";
}

