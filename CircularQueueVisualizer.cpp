#include "CircularQueueVisualizer.h"
#include "need.h"
#include <iostream>
#include <iomanip>
using namespace std;
CircularQueueVisualizer::CircularQueueVisualizer(int cap) :
 data(cap, 0), occupied(cap, false), frontIndex(0), rearIndex(0), count(0), capacity(cap) {}

 bool CircularQueueVisualizer::empty() const{
    return count == 0;
 }

 bool CircularQueueVisualizer::full() const{
    return count == capacity;
 }

 int CircularQueueVisualizer::size() const{
    return count;
 }

 void CircularQueueVisualizer::display() const{
    cout << "\n Queue State (count = " << count << "/" << capacity
     << ", frontIndex = " << frontIndex
     << ", rearIndex = " << rearIndex << "):\n";

     //printing index  headers
     cout << "Index: ";
     for(int i = 0; i < capacity; i++){
        cout << " [" << i << "] "; 
     }
     cout << "\nValue: ";

     //printing slots
     for(int i = 0; i < capacity; i++){
        if(occupied[i]){
            cout << " " << setw(4) << data[i] << " ";
        } else {
            cout << " [emp] ";
        }
     }
     cout << "\n";

     //printing front and rear 
     for(int i = 0; i < capacity; i++){
        if(i == frontIndex && i == rearIndex){
            cout << " F/R ";
        } else if (i == frontIndex){
            cout << "Front";
        } else if (i == rearIndex){
            cout << "Rear";
        } else {
            cout << "  ";
        }
     }
     cout << "\n";
 }

 //enqueuing 
 void CircularQueueVisualizer::enqueue(int value){
    cout << "\n--- Before Enqueue(" << value << ") ---";
    display();
 }