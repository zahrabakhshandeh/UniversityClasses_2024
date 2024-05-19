#include <iostream>
#include <list>

template <typename Type>
class Simple_tree {
private:
    Type node_value;
    Simple_tree *parent_node;
    std::list<Simple_tree *> children;

public:
    // Constructor
    Simple_tree(Type const &value, Simple_tree *parent = nullptr)
        : node_value(value), parent_node(parent) {}

    // Accessor for node value
    Type value() const {
        return node_value;
    }

    // Accessor for parent node
    Simple_tree *parent() const {
        return parent_node;
    }

    // Returns the number of children
    int degree() const {
        return children.size();
    }

    // Check if it is the root node
    bool is_root() const {
        return parent_node == nullptr;
    }

    // Check if it is a leaf node
    bool is_leaf() const {
        return children.empty();
    }

    // Returns the nth child
    Simple_tree *child(int n) const {
        if (n < 0 || n >= degree()) {
            return nullptr;
        }
        auto it = children.begin(); //[1, 20, 3, 47]
        std::advance(it, n);
        return *it;
    }

    // Calculates the height of the tree
    int height() const {
        if (is_leaf()) {
            return 0;
        }
        int max_height = 0;
        for (auto child : children) {
            max_height = std::max(max_height, child->height());
        }
        return max_height + 1;
    }

    // Inserts a new node with a value under this node
    void insert(Type const &value) {
        Simple_tree *new_node = new Simple_tree(value, this);
        children.push_back(new_node);
    }

    // Detaches this node from its parent
    void detach() {
        if (is_root()) {
            return;
        }
        auto &siblings = parent_node->children;
        siblings.remove(this);
        parent_node = nullptr;
    }
};

int main() {
    // Example usage
    Simple_tree<int> root(1);
    root.insert(2);
    root.insert(3);
    //root.detach()

    Simple_tree<int> *child1 = root.child(0);
    child1->insert(4);

    std::cout << "Root value: " << root.value() << std::endl;
    std::cout << "Root degree: " << root.degree() << std::endl;
    std::cout << "Root height: " << root.height() << std::endl;
    std::cout << "Child1 value: " << child1->value() << std::endl;
    std::cout << "Child1 is leaf: " << child1->is_leaf() << std::endl;

    return 0;
}
