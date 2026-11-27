#include "LinkedListVisualizer.h"
#include "need.h"
#include <iostream>
using namespace std;

LinkedListVisualizer::LinkedListVisualizer(): head(nullptr), count(0) {}

LinkedListVisualizer::~LinkedListVisualizer(){
    while(head!=nullptr){
        Node* removed = head;
        head = head -> next;
        delete removed;
    }
    count = 0;
}

bool LinkedListVisualizer::empty() const {
    return head == nullptr;
}

int LinkedListVisualizer::size() const{
    return count;
}

void LinkedListVisualizer::display() const{
    cout<<"\nLinked List State(size = " << count << "):\n";
    cout << "head -> ";
}