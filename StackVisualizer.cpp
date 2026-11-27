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

void StackVisualizer::push(int value){
    cout << "\n-- BEFORE PUSH(" << value << ") ---";
    display();
    values.push_back(value);
    cout << "\n[Step] Pushed " << value << " onto top of stack.\n";
    cout << "-- AFTER PUSH(" << value << ") ---";
    display();
    cout << "Complexity: Time O(1) amortized | Auxiliary Space O(1)\n";
}

void StackVisualizer::pop(){
    cout << "\n-- BEFORE POP() ---";
    display();

    if(empty()){
        cout << "\n [Underflow Error] Stack is empty. Nothing to pop.\n";
        cout << "Complexity: Time O(1) | Auxiliary Space O(1)\n";
        return;
    }
    int removedVal = values.back();
    values.pop_back();

    cout << "\n[Step] Popped " << removedVal << " from top of stack.\n";
    cout << "--- AFTER POP() ---";
    display();
    cout << "Complexity: Time O(1) | Auxiliary Space O(1)\n";
}

void StackVisualizer::top() const{
    if(empty()){
        cout << "\n [Underflow Error] Stack is empty. No top element.\n";
    } else{
        cout << "\n Top elemenet: " << values.back() << " (stack unchanged)\n";
    }
    cout << "Complexity: Time O(1) | Auxiliary Space O(1)\n";
}

