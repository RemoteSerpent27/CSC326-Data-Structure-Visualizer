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
    Node* current = head;
    while(current != nullptr) {
        cout << "[" << current -> data << " | next] -> ";
        current = current -> next;
    }
    cout <<"nullptr\n";
}

void LinkedListVisualizer::pushFront(int value){
    cout << "\n-- BEFORE INSERT AT BEGINNING (" << value << ") ---";
    display();

    Node* newNode = new Node{value, head};
    head = newNode;
    count++;

    cout << "\n[Pointer Update] newNode = new node{" << value << ", head}; head = newNodee;\n";
    cout << "--- AFTER INSERT AT BEGINNING (" << value << ") ---";
    display();
    cout << "Complexity: Time O(1) | Auxiliary Space O(1)\n";
}

void LinkedListVisualizer::pushBack(int value){
    cout << "\n--- BEFORE INSERT AT END(" << value << ") ---";
    display();
    Node* newNode = new Node{value, nullptr};
    if(head == nullptr){
        head = newNode;
        cout << "\n[Pointer Update] List was empty -> head = newNode;\n";
    } else {
        Node* current = head;
        int steps = 0;
        while(current->next != nullptr){
            current = current -> next;
            steps++;
        }
        current -> next = newNode;
        cout << "\n[Pointer Update] Traversed " << steps << " link(s) to tail -> tail -> next = newNode;\n";
    }
    cout++;
}