#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Class definition for the tree node
template <typename Type>
class TreeNode {
public:
    Type value;
    vector<TreeNode*> children;

    TreeNode(Type val) : value(val) {}

    void add_child(TreeNode* child) {
        children.push_back(child);
    }
};

// Function to perform DFS on the tree
template <typename Type>
void DFS(TreeNode<Type>* root) {
    if (!root) return;

    stack<TreeNode<Type>*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode<Type>* node = s.top();
        s.pop();
        cout << node->value << " ";

        for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
            s.push(*it);
        }
    }
}

int main() {
    // Create the tree nodes
    TreeNode<string>* root = new TreeNode<string>("A");
    TreeNode<string>* child1 = new TreeNode<string>("B");
    TreeNode<string>* child2 = new TreeNode<string>("C");
    TreeNode<string>* grandchild1 = new TreeNode<string>("D");
    TreeNode<string>* grandchild2 = new TreeNode<string>("E");

    // Build the tree
    root->add_child(child1);
    root->add_child(child2);
    child1->add_child(grandchild1);
    child2->add_child(grandchild2);
    cout << "DFS traversal starting from the root:" << endl;
    DFS(root);

    // Clean up dynamically allocated memory
    delete root;
    delete child1;
    delete child2;
    delete grandchild1;
    delete grandchild2;

    return 0;
}
