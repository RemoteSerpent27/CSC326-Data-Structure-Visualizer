#ifndef STACK_VISUALIZER_H
#define STACK_VISUALIZER_H
#include <vector>
#include <string>

class StackVisualizer {
    private:
    std::vector<int> values;
    public: 
    StackVisualizer();
    bool empty() const;
    int size() const;

    void push(int value);
    void pop();
    void top() const;
    void display() const;
    void checkBalancedDeLimiters(const std::string& expression) const;
    void runMenu();
};
#endif