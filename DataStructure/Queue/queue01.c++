#include <iostream>
#include <stdexcept>

// Definition of the node class used in the singly linked list
template <typename Type>
class Single_node {
public:
    Type data;
    Single_node<Type>* next;

    Single_node(Type const &data, Single_node<Type>* next = nullptr)
        : data(data), next(next) {}
};

// Definition of the singly linked list class
template <typename Type>
class Single_list {
private:
    Single_node<Type>* head_;
    Single_node<Type>* tail_;
    int size_;

public:
    Single_list() : head_(nullptr), tail_(nullptr), size_(0) {}
    ~Single_list() {
        while (!empty()) {
            pop_front();
        }
    }

    int size() const { return size_; }
    bool empty() const { return head_ == nullptr; }
    Type front() const {
        if (empty()) throw std::logic_error("List is empty");
        return head_->data;
    }
    Type back() const {
        if (empty()) throw std::logic_error("List is empty");
        return tail_->data;
    }
    void push_back(Type const &value) {
        Single_node<Type>* newNode = new Single_node<Type>(value);
        if (empty()) {
            head_ = tail_ = newNode;
        } else {
            tail_->next = newNode;
            tail_ = newNode;
        }
        size_++;
    }
    Type pop_front() {
        if (empty()) throw std::logic_error("List is empty");
        Type data = head_->data;
        Single_node<Type>* temp = head_;
        head_ = head_->next;
        delete temp;
        if (--size_ == 0) {
            tail_ = nullptr;
        }
        return data;
    }
};

// Definition of the Queue class using the singly linked list
template <typename Type>
class Queue {
private:
    Single_list<Type> list;

public:
    bool empty() const {
        return list.empty();
    }

    void push(Type const &obj) {
        list.push_back(obj);
    }

    Type front() const {
        if (empty()) {
            throw std::underflow_error("Queue is empty");
        }
        return list.front();
    }

    Type pop() {
        if (empty()) {
            throw std::underflow_error("Queue is empty");
        }
        return list.pop_front();
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
