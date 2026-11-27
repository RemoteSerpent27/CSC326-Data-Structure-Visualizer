#include "StackVisualizer.h"
#include "need.h"
#include <iostream>
#include <iomanip>
using namespace std;

StackVisualizer::StackVisualizer(){}

bool StackVisualizer::empty() const{
    return values.empty();
}

int StackVisualizer::size() const{
    return static_cast<int>(values.size());
}

void StackVisualizer::display() const{
    cout << "\nStack State (LIFO | size = " << values.size() << "):\n";
    if(values.empty()){
        cout << " [ empty stack ]\n";
        return;
    }
    for(int i = static_cast<int>(values.size()) - 1; i >= 0; i--){
        cout << " | " << setw(5) << values[i] << " |";
        if (i == static_cast<int>(values.size()) - 1){
            cout << "  <-- TOP";
        }
        cout << "\n  +-----+\n";
    }
}

