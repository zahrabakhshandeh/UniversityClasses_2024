#include <iostream>
#include <stdexcept>

template <typename Type>
class Single_node {
private:
    Type node_value;                 // Data stored in the node
    Single_node<Type>* next_node;    // Pointer to the next node

public:
    Single_node(Type const &data, Single_node<Type>* next = nullptr)
        : node_value(data), next_node(next) {}

    Type get_value() const {
        return node_value;
    }

    Single_node<Type>* get_next_node() const {
        return next_node;
    }

    void set_next_node(Single_node<Type>* next) {
        next_node = next;
    }
};

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

    Single_node<Type>* begin() const {
        return head_;
    }

    void push_back(Type const &value) {
        Single_node<Type>* newNode = new Single_node<Type>(value);
        if (empty()) {
            head_ = tail_ = newNode;
        } else {
            tail_->set_next_node(newNode);  // Correctly using setter
            tail_ = newNode;
        }
        size_++;
    }

    Type pop_front() {
        if (empty()) throw std::logic_error("List is empty");
        Type data = head_->get_value();
        Single_node<Type>* temp = head_;
        head_ = head_->get_next_node();
        delete temp;
        if (--size_ == 0) {
            tail_ = nullptr;
        }
        return data;
    }

    void reverse() {
        Single_node<Type>* prev = nullptr;
        Single_node<Type>* curr = head_;
        Single_node<Type>* next = nullptr;
        tail_ = head_;
        while (curr != nullptr) {
            next = curr->get_next_node();
            curr->set_next_node(prev);  // Correctly using setter
            prev = curr;
            curr = next;
        }
        head_ = prev;
    }

    bool erase(Type const &value) {
        Single_node<Type>* prev = nullptr;
        Single_node<Type>* curr = head_;
        while (curr != nullptr) {
            if (curr->get_value() == value) {
                if (prev) {
                    prev->set_next_node(curr->get_next_node());  // Correctly using setter
                } else {
                    head_ = curr->get_next_node();
                }
                if (curr == tail_) {
                    tail_ = prev;
                }
                delete curr;
                --size_;
                return true;
            }
            prev = curr;
            curr = curr->get_next_node();
        }
        return false;
    }

    int count(Type const &value) const {
        int count = 0;
        Single_node<Type>* node = begin();
        while (node != nullptr) {
            if (node->get_value() == value) {
                ++count;
            }
            node = node->get_next_node();
        }
        return count;
    }
    
    // Check if the list contains a specific value
    bool contains(Type const &value) const {
        Single_node<Type>* current = head_;
        while (current != nullptr) {
            if (current->get_value() == value) {
                return true; // Value found
            }
            current = current->get_next_node();
        }
        return false; // Value not found
    }
};

void staticLinkedListExample() {
    Single_list<int> staticList;  // Statically allocated linked list
    staticList.push_back(1);
    staticList.push_back(2);
    staticList.push_back(3);

    // Output the contents of the list
    std::cout << "Static Linked List contents: ";
    for (Single_node<int>* node = staticList.begin(); node != staticList.end(); node = node->get_next_node()) {
        std::cout << node->get_value() << " ";
    }
    std::cout << std::endl;
}

Single_list<int>* dynamicLinkedListExample() {
    Single_list<int>* dynamicList = new Single_list<int>();  // Dynamically allocated linked list
    dynamicList->push_back(4);
    dynamicList->push_back(5);
    dynamicList->push_back(6);

    // Output the contents of the list
    std::cout << "Dynamic Linked List contents: ";
    for (Single_node<int>* node = dynamicList->begin(); node != dynamicList->end(); node = node->get_next_node()) {
        std::cout << node->get_value() << " ";
    }
    std::cout << std::endl;

    return dynamicList;  // Return the dynamically allocated list
}

int main() {
    Single_list<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(20);

    std::cout << "List contents: ";
    for (Single_node<int>* node = list.begin(); node != nullptr; node = node->get_next_node()) {
        std::cout << node->get_value() << " ";
    }
    std::cout << std::endl;

    std::cout << "Number of '20': " << list.count(20) << std::endl;

    list.reverse();
    std::cout << "Reversed List: ";
    for (Single_node<int>* node = list.begin(); node != nullptr; node = node->get_next_node()) {
        std::cout << node->get_value() << " ";
    }
    std::cout << std::endl;

    if (list.erase(20)) {
        std::cout << "After erasing '20': ";
        for (Single_node<int>* node = list.begin(); node != nullptr; node = node->get_next_node()) {
            std::cout << node->get_value() << " ";
        }
        std::cout << std::endl;
    }

     Single_list<int> list2;
    list2.push_back(10);
    list2.push_back(20);
    list2.push_back(30);

    // Test if list contains specific numbers
    std::cout << "Does the list contain 20? " << (list2.contains(20) ? "Yes" : "No") << std::endl;
    std::cout << "Does the list contain 40? " << (list2.contains(40) ? "Yes" : "No") << std::endl;

    return 0;
}

