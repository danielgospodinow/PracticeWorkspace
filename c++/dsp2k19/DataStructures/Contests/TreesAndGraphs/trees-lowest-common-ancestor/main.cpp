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

bool containsElement(Node *root, int element) {
    if(!root) {
        return false;
    }

    if(root->data == element) {
        return true;
    }

    return (root->data > element) ? containsElement(root->left, element) : containsElement(root->right, element);
}

Node *lca(Node *root, int v1,int v2) {
    if(!root) {
        return nullptr;
    }

    int currentData = root->data;
    int smallerData = (v1 < v2) ? v1 : v2;
    int greaterData = (v1 > v2) ? v1 : v2;

    if(currentData >= smallerData && currentData <= greaterData) {
        return root;
    } else {
        if(greaterData < currentData) {
            return lca(root->left, v1, v2);
        } else {
            return lca(root->right, v1, v2);
        }
    }
}

int main() {
    cout << "Hello World!" << endl;
    return 0;
}
