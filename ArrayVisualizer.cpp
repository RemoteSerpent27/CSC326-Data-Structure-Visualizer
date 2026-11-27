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

void ArrayVisualizer::search(int target) const {
    std::cout << "\n--- LINEAR SEARCH FOR " << target << " ---";
    display();

    if (values.empty()) {
        std::cout << "[Not Found] Array is empty.\n";
        std::cout << "Complexity: Time O(1) | Auxiliary Space O(1)\n";
        return;
    }

    std::cout << "Scan Trace: ";
    for (size_t i = 0; i < values.size(); ++i) {
        std::cout << "[" << i << "]=" << values[i];
        if (values[i] == target) {
            std::cout << " -> MATCH FOUND at index " << i << "!\n";
            std::cout << "Complexity: Time O(n) | Auxiliary Space O(1)\n";
            return;
        }
        if (i + 1 < values.size()) std::cout << " -> ";
    }

    std::cout << " -> NOT FOUND (returned -1).\n";
    std::cout << "Complexity: Time O(n) | Auxiliary Space O(1)\n";
}

void ArrayVisualizer::insertAt(int index, int value) {
    if (index < 0 || index > static_cast<int>(values.size())) {
        std::cout << "\n[Bounds Error] Valid insertion indexes are 0 through " << values.size() << ".\n";
        return;
    }

    std::cout << "\n--- BEFORE INSERT(" << value << " at index " << index << ") ---";
    display();

    int shiftedCount = static_cast<int>(values.size()) - index;
    if (shiftedCount > 0) {
        std::cout << "\n[Shift Step] Shifting " << shiftedCount
                  << " element(s) right from index " << index << " to " << values.size() - 1 << ".\n";
    } else {
        std::cout << "\n[Append Step] Inserting at end (index " << index << "). No elements shifted.\n";
    }

    values.insert(values.begin() + index, value);

    std::cout << "--- AFTER INSERT(" << value << " at index " << index << ") ---";
    display();
    if (shiftedCount == 0) {
        std::cout << "Complexity: Time O(1) amortized (append) | Auxiliary Space O(1)\n";
    } else {
        std::cout << "Complexity: Time O(n) (right shift required) | Auxiliary Space O(1)\n";
    }
}

void ArrayVisualizer::removeAt(int index) {
    if (values.empty()) {
        std::cout << "\n[Underflow Error] Array is empty. Nothing to remove.\n";
        return;
    }
    if (index < 0 || index >= static_cast<int>(values.size())) {
        std::cout << "\n[Bounds Error] Valid removal indexes are 0 through " << values.size() - 1 << ".\n";
        return;
    }

    std::cout << "\n--- BEFORE REMOVE AT INDEX " << index << " ---";
    display();

    int removedVal = values[index];
    int shiftedCount = static_cast<int>(values.size()) - 1 - index;

    values.erase(values.begin() + index);

    if (shiftedCount > 0) {
        std::cout << "\n[Shift Step] Removed " << removedVal << "; shifted " << shiftedCount
                  << " later element(s) left to fill gap.\n";
    } else {
        std::cout << "\n[Pop Step] Removed last element (" << removedVal << "). No elements shifted.\n";
    }

    std::cout << "--- AFTER REMOVE AT INDEX " << index << " ---";
    display();
    if (shiftedCount == 0) {
        std::cout << "Complexity: Time O(1) (end removal) | Auxiliary Space O(1)\n";
    } else {
        std::cout << "Complexity: Time O(n) (left shift required) | Auxiliary Space O(1)\n";
    }
}