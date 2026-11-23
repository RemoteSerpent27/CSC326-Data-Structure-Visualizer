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
        need::printDivider();
        cout << "1. Array/Vector "<< endl;
        cout << "2. Linked List(Singly) " << endl;
        cout << "3. Stack " << endl;
        cout << "4. Circular Queue Array " << endl;
        need::printDivider();

        choice = need::getValidInt("Select a option(1-5): ", 1, 5);
        switch(choice){
            case 1: runArrayMenu(); break;
            case 2: runLinkedList(); breal;
            case 3: runStackMenu(); break
        }
    }

    return 0;
}