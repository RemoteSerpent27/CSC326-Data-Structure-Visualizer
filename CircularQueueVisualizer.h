#ifndef CIRCULAR_QUEUE_VISUALIZER_H
#define CIRCULAR_QUEUE_VISUALIZER_H

#include <vector>

class CircularQueueVisualizer{
private:
 std::vector<int> data;
 std::vector<bool> occupied;
 int frontIndex; 
 int rearIndex;
 int count;
 int capacity;

 public:
  explicit CircularQueueVisualizer(int cap = 5);
}

#endif CIRCULAR_QUEUE_VISUALIZER_H