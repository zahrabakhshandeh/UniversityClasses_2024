#include <iostream>
#include <stdexcept>

template <typename Type>
class Queue {
private:
    int queue_size;
    int ifront;
    int iback;
    int array_capacity;
    Type *array;

    // Function to resize the array when it becomes full
    void resize() {
        int new_capacity = array_capacity * 2;  // Double the current capacity
        Type *new_array = new Type[new_capacity];

        for (int i = 0, index = ifront; i < queue_size; ++i, index = (index + 1) % array_capacity) {
            new_array[i] = array[index];
        }

        delete[] array;
        array = new_array;
        array_capacity = new_capacity;
        ifront = 0;         // Reset the front index
        iback = queue_size; // Set the back index to the size of the queue
    }

public:
    // Constructor with default capacity
    Queue(int capacity = 10) : queue_size(0), ifront(0), iback(0), 
    array_capacity(capacity) {
        array = new Type[array_capacity];
    }

    // Destructor to release the array memory
    ~Queue() {
        delete[] array;
    }

    // Check if the queue is empty
    bool empty() const {
        return queue_size == 0;
    }

    // Return the front element of the queue
    Type front() const {
        if (empty()) {
            throw std::underflow_error("Queue is empty");
        }
        return array[ifront];
    }

    // Add an element to the end of the queue
    void push(Type const &value) {
        if (queue_size == array_capacity) {
            resize();
        }
        array[iback] = value;
        iback = (iback + 1) % array_capacity;
        queue_size++;
    }

    // Remove the front element from the queue and return its value
    Type pop() {
        if (empty()) {
            throw std::underflow_error("Queue is empty");
        }
        Type frontElement = array[ifront];
        ifront = (ifront + 1) % array_capacity;
        queue_size--;
        return frontElement;
    }
};

int main() {
    Queue<int> queue;
    queue.push(10);
    queue.push(20);
    queue.push(30);

    std::cout << "Front of the queue: " << queue.front() << std::endl;

    while (!queue.empty()) {
        std::cout << "Popping from the queue: " << queue.pop() << std::endl;
    }

    return 0;
}
