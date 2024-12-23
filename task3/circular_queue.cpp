#include "circular_queue.hpp"
#include <vector>

CircularQueue::CircularQueue(size_t max_size) : max_capacity(max_size), current_size(0), head_index(0), tail_index(0) {
    storage.resize(max_size);  // Pre-allocate exact size
}

bool CircularQueue::Push(int value) {
    if (IsFull()) {
        return false;
    }
    storage[tail_index] = value;
    tail_index = (tail_index + 1) % max_capacity;
    current_size++;
    return true;
}

bool CircularQueue::Pop() {
    if (IsEmpty()) {
        return false;
    }
    head_index = (head_index + 1) % max_capacity;
    current_size--;
    return true;
}

int CircularQueue::Front() const {
    if (IsEmpty()) {
        return -1;
    }
    return storage[head_index];
}

int CircularQueue::Back() const {
    if (IsEmpty()) {
        return -1;
    }
    return storage[(tail_index - 1 + max_capacity) % max_capacity];
}

bool CircularQueue::IsEmpty() const {
    return current_size == 0;
}

bool CircularQueue::IsFull() const {
    return current_size == max_capacity;
}
