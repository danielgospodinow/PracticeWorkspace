#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

int height(Node* root) {
    return (!root || (!root->left && !root->right)) ?
                0 :
                1 + max(height(root->left), height(root->right));
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
