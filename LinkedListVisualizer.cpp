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
    count++;
    cout <<"--- AFTER INSERT AT END(" << value << ") ---";
    display();
    cout << "Complexity: Time O(n) (head - only representation) | Auxiliary Space O(1)\n";
}

void LinkedListVisualizer::insertAt(int index, int value){
    if(index < 0  || index > count){
        cout << "\n[Bounds Error] Valid insertion inexes are 0 throuhg " << count << ".\n";
        return;
    }
    if(index == 0){
        pushFront(value);
        return;
    }
    cout << "\n--- BEFORE INSERT AT INDEX " << index << " (" << value << ") ---";
    display();

    Node* previous = head;
    for(int i = 0; i < index - 1; i++){
        previous = previous -> next;
    }

    Node* newNode = new Node{value, previous -> next};
    previous -> next= newNode;
    count++;

    cout << "\n[Pointer Update] Reached predecessor (" << previous -> data <<
    ") -> newNode-> next = previous-next; previous->next = newNode;\n";
    cout << "--- AFTER INSERT AT INDEX " << index << " (" << value << ") --- ";
    display();
    cout << "Complexity: Time O(n) | Auxiliary Space O(1)\n";
}

void LinkedListVisualizer::removeByValue(int target){
    std::cout << "\n--- BEFORE DELETE BY VALUE (" << target << ") ---";
    display();

    if (head == nullptr) {
        cout << "\n[Underflow Error] List is empty (head == nullptr). Nothing to delete.\n";
        cout << "Complexity: Time O(1) | Auxiliary Space O(1)\n";
        return;
    }

    // Special case: removing head node
    if (head->data == target) {
        Node* removed = head;
        head = head->next;
        delete removed;
        --count;

        cout << "\n[Pointer Update] Target at head -> removed = head; head = head->next; delete removed;\n";
        cout << "--- AFTER DELETE BY VALUE (" << target << ") ---";
        display();
        cout << "Complexity: Time O(1) | Auxiliary Space O(1)\n";
        return;
    }

    // Search for target with previous and current pointers
    Node* previous = head;
    Node* current = head->next;
    while (current != nullptr && current->data != target) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "\n[Not Found] Value " << target << " is not in the list. No links changed.\n";
        cout << "Complexity: Time O(n) | Auxiliary Space O(1)\n";
        return;
    }

    Node* removed = current;
    previous->next = current->next;
    delete removed;
    --count;

    cout << "\n[Pointer Update] Saved removed = current (" << target
              << ") -> previous->next = current->next; delete removed;\n";
    cout << "--- AFTER DELETE BY VALUE (" << target << ") ---";
    display();
    cout << "Complexity: Time O(n) | Auxiliary Space O(1)\n";
}
