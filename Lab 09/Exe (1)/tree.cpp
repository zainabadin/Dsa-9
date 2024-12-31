#include <iostream>
#include <stack>
#include <string>
using namespace std;

class TNode {
public:
    char data;
    TNode *left, *right;

    TNode(char value){
        data = value; 
        left = nullptr;
        right = nullptr;
        }
};

TNode* constructTree(string postfix) {
    stack<TNode*> s;

    for (char ch : postfix) {
        TNode* curr = new TNode(ch);

        if (isalpha(ch)) {
            s.push(curr);
        } else {
            TNode* right = s.top(); s.pop();
            TNode* left = s.top(); s.pop();

            curr->left = left;
            curr->right = right;
            s.push(curr);
        }
    }
    return s.top();
}

void postorder(TNode* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}

int main() {
    string postfix = "ab+ef*g*-";
    TNode* root = constructTree(postfix);

    cout << "Postorder traversal: ";
    postorder(root); 
    cout << endl;

    return 0;
}
