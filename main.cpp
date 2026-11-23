#include <iostream>
#include "need.h"
#include "CircularQueueVisualizer.h"

using namespace std;

void runArrayMenu(){
    cout<<"Array/ Vector Visualizer - To be added"<< endl;
}

void runLinkedList(){
    cout << "Linked Lisr visualizer(singly) to be added" << endl;
}

void runStackMenu(){
    cout << "Stack visualizer, to be added" << endl;
}

int main(){
    CircularQueueVisualizer queueVis(5);
    int choice = 0;

    while(choice != 5){
        need::printDivider();
        cout << " CSC-325 Data Structures Visualizer" << endl;
    }

    return 0;
}