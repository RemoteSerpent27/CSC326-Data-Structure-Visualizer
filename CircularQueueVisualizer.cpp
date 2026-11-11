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

    if(full()){
        cout << "[Overflow Error] Queue is now full, cannot enqueue " << value << ".\n";
        cout << "Complexity: O(1) | Auxiliary Space O(1)\n";
        return;
    }
    int oldRear = rearIndex;
    data[rearIndex] = value;
    occupied[rearIndex] = true;
    rearIndex = (rearIndex + 1) % capacity;
    count++;

    cout << "\n[STEP] Wrote " << value << " at index " << oldRear
         << ", wrapped rearIndex: (" << oldRear << "+ 1) % " << capacity << " = " << rearIndex << ".\n";
    cout << "---AFTER ENQUEUE(" << value << ") ---";
    display();
    cout << "Complexity: Time O(1) | Auxiliry Space O(1)\n";
 }

 void CircularQueueVisualizer::dequeue() {
    cout << "\n--- Before Dequeue() ---";
    display();
 }