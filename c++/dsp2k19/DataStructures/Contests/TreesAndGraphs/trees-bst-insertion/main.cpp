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

Node* insert(Node* root, int data) {
    if(!root) {
        return new Node(data);
    }

    if(root->data > data) {
        root->left = insert(root->left, data);
    } else if (root->data < data) {
        root->right = insert(root->right, data);
    }

    return root;
}

int main()
{
    std::cout << "Hello World!" << std::endl;
    return 0;
}
