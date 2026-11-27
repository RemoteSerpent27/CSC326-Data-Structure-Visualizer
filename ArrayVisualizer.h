#ifndef ARRAY_VISUALIZER_H
#define ARRAY_VISUALIZER_H
#include <vector>
using namespace std;
class ArrayVisualizer {
    private:
    std::vector<int> values;
    public:
    ArrayVisualizer();
    void display() const;
    void accessAt(int index) const;
    void search(int target) const;
    void insertAt(int index, int value);
    void removeAt(int index);
    void runMenu();
};
#endif