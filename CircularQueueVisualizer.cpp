#include "CircularQueueVisualizer.h"
#include "need.h"
#include <iostream>
#include <iomanip>

CircularQueueVisualizer::CircularQueueVisualizer(int cap) :
 data(cap, 0), occupied(cap, false), frontIndex(0), rearIndex(0), count(0), capacity(cap) {}
 