#include <iostream>
using namespace std;

class TNode {
public:
    int data;
    TNode* left;
    TNode* right;

    TNode(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

int count_leaf(TNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return count_leaf(root->left) + count_leaf(root->right);
}

int count_nonleaf(TNode* root) {
    if (!root || (!root->left && !root->right)) return 0;
    return 1 + count_nonleaf(root->left) + count_nonleaf(root->right);
}

bool isleaf(TNode* root, int value) {
    if (!root) return false;
    if (root->data == value && !root->left && !root->right) return true;
    return isleaf(root->left, value) || isleaf(root->right, value);
}

// Example usage
int main() {
    TNode* root = new TNode(1);
    root->left = new TNode(2);
    root->right = new TNode(3);
    root->left->left = new TNode(4);
    root->left->right = new TNode(5);

    cout << "Leaf nodes: " << count_leaf(root) << endl;
    cout << "Non-leaf nodes: " << count_nonleaf(root) << endl;
    cout << "Is 4 a leaf node? " << (isleaf(root, 4) ? "Yes" : "No") << endl;

    return 0;
}
