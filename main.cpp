#include <iostream>
#include "need.h"
#include "ArrayVisualizer.h"
#include "LinkedListVisualizer.h"
#include "StackVisualizer.h"
#include "CircularQueueVisualizer.h"
//command to start: g++ -std=c++17 main.cpp LinkedListVisualizer.cpp CircularQueueVisualizer.cpp -o visualizer && ./visualizer
//command for terminal: Control + `
using namespace std;

void runArrayMenu(){
    cout<<"Array/ Vector Visualizer - To be added"<< endl;
}

void runLinkedList(){
    cout << "Linked List visualizer(singly) to be added" << endl;
}

void runStackMenu(){
    cout << "Stack visualizer, to be added" << endl;
}

int main(){
    ArrayVisualizer arrayViz;
    LinkedListVisualizer listViz;
    StackVisualizer stackViz;
    CircularQueueVisualizer queueVis(5);
    int choice = 0;

    while(choice != 5){
        need::printDivider();
        cout << " CSC-326 Data Structures Visualizer" << endl;
        need::printDivider();
        cout << "1. Array / Vector "<< endl;
        cout << "2. Singly Linked List " << endl;
        cout << "3. Stack " << endl;
        cout << "4. Circular Queue Array " << endl;
        cout << "5. Exit " << endl;
        need::printDivider();

        choice = need::getValidInt("Select a option(1-5): ", 1, 5);
        switch(choice){
            case 1: arrayViz.runMenu(); break;
            case 2: listViz.runMenu(); break;
            case 3: stackViz.runMenu(); break;
            case 4: queueVis.runMenu(); break;
            case 5: cout << "Exiting, Goodbye." << endl; break;
        }
    }

    return 0;
}