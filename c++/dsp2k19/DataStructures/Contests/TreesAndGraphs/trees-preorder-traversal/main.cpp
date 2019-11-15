#include <iostream>

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

void preOrder(Node *root) {
    if(!root) {
        return;
    }

    if(!root->left && !root->right) {
        std::cout << root->data << " ";
        return;
    }

    std::cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    std::cout << "Hello World!" << std::endl;
    return 0;
}
