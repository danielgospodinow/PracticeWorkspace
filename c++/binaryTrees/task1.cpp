#include <iostream>

struct Node 
{ 
    int x; 
    Node *left, *right;
};

bool complement(Node* const& t1, Node* const& t2)
{
    if(!t1)
        return false;
    if(!t2)
        return true;

    return (t2->x == t1->x && complement(t1->left, t2->left) && complement(t1->right, t2->right));
}

int main()
{
    return 0;
}