#include "LinkedListVisualizer.h"
#include "need.h"
#include <iostream>
using namespace std;

LinkedListVisualizer::LinkedListVisualizer(): head(nullptr), count(0) {}

LinkedListVisualizer::~LinkedListVisualizer(){
    while(head!=nullptr)
}