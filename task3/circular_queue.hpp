#pragma once

#include <vector>

class CircularQueue {
private:
    std::vector<int> storage;          // Dynamic array to store elements
    size_t max_capacity;               // Maximum size of the queue
    size_t current_size;               // Current count of elements
    size_t head_index;                 // Index of the front element
    size_t tail_index;                 // Index of the rear element

public:
    CircularQueue(size_t max_size);    // Constructor

    bool Push(int value);              // Add value to the end
    bool Pop();                        // Remove value from the front
    int Front() const;                 // Get front value
    int Back() const;                  // Get back value
    
    bool IsEmpty() const;              // Check if empty
    bool IsFull() const;               // Check if full
};
