#include <iostream>
#include <queue>
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

// Function to perform BFS on the tree
template <typename Type>
void BFS(TreeNode<Type>* root) {
    if (!root) return;

    queue<TreeNode<Type>*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode<Type>* node = q.front();
        q.pop();
        cout << node->value << " ";

        // Enqueue all children of the current node
        for (TreeNode<Type>* child : node->children) {
            q.push(child);
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

    // Perform BFS starting from the root
    cout << "BFS traversal starting from the root:" << endl;
    BFS(root);

    // Clean up dynamically allocated memory
    delete root;
    delete child1;
    delete child2;
    delete grandchild1;
    delete grandchild2;

    return 0;
}
