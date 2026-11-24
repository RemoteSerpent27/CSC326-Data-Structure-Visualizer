#ifndef LINKED_LIST_VISUALIZER_H
#define LINKED_LIST_VISUALIZER_H

struct Node{
    int data;
    Node* next;
};

class LinkedListVisualizer{
    private:
    Node* head;
    int count;

    public:
    LinkedListVisualizer();
    ~LinkedListVisualizer();

    bool empty() const;
    int size() const;

    void pushFront(int value);
    void pushBack(int value);
    void insertAt(int index, int value);
    void removeByValue(int target);
    void search(int target) const;
    void display() const;
    void runMenu();
};

#endif