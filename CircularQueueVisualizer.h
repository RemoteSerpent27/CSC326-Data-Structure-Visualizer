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
  bool empty() const;
  bool full() const;
  int size() const;

  void enqueue(int value);
  void dequeue();
  void front() const;
  void display() const;
  void runMenu();
  };

#endif CIRCULAR_QUEUE_VISUALIZER_H