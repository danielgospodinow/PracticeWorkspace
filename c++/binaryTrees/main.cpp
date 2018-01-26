#include "binaryTree.hpp"
#include <math.h>
#include <vector>
#include <map>
#include <queue>

template <typename T>
struct Node
{
    Node(T _data, Node* const& _next = nullptr):
        data(_data), next(_next)
    {}

    T data;
    Node* next;
};

void addToList(Node<int>*& list, int val)
{
    if(!list)
    {
        list = new Node<int>(val);
        return;    
    }

    Node<int>* start = list;
    while(list->next)
        list = list->next;

    list->next = new Node<int>(val);
    list = start;
}

void clearContainer(Node<int>* & list)
{
    while(list)
    {
        Node<int>* toDel = list;
        list = list->next;
        delete toDel;
    }
}

template <typename Func>
void mergeSplit(Node<int>* container, Func f, Node<int>* & evenContainer, Node<int>* & oddContainer)
{
    clearContainer(evenContainer);
    clearContainer(oddContainer);

    while(container)
    {
        int currentIterNum = f(container->data);
        (currentIterNum%2==0) ? (addToList(evenContainer, currentIterNum)) : (addToList(oddContainer, currentIterNum));

        container = container->next;
    }
}

void printList(Node<int>* list)
{
    while(list)
    {
        std::cout << list->data << " ";
        list = list->next;
    }

    std::cout << std::endl;
}

int getCount(BinaryTree<int>::Node* root)
{
    if(!root)
        return 0;

    return 1 + getCount(root->left) + getCount(root->right);
}

int getEvensCount(BinaryTree<int>::Node* root)
{
    if(!root)
        return 0;

    return (root->data % 2 == 0 ? 1 : 0) + getEvensCount(root->left) + getEvensCount(root->right);
}

template <typename BoolPredicate>
int searchCount(BinaryTree<int>::Node* root, BoolPredicate f)
{
    if(!root)
        return 0;

    return (f(root->data) ? 1 : 0) + searchCount(root->left, f) + searchCount(root->right, f);
}

int getHeight(BinaryTree<int>::Node* root)
{
    if(!root)
        return 0;

    return 1 + std::max(getHeight(root->left), getHeight(root->right));
}

int getLeavesCount(BinaryTree<int>::Node* root)
{
    if(!root)
        return 0;

    if(!root->left && !root->right)
        return 1;

    return getLeavesCount(root->left) + getLeavesCount(root->right);
}

int getMaxLeaf(BinaryTree<int>::Node* root)
{
    if(!root)
        return 0;

    int arr[3] = { root->data, getMaxLeaf(root->left), getMaxLeaf(root->right) };

    int max = arr[0];
    for(int i = 1; i < 3; ++i)
        if(arr[i] > max)
            max = arr[i];
    
    return max;
}

int getElement(BinaryTree<int>::Node* root, const char* strPath)
{
    if(!root)
        return 0;

    if(!*strPath)
        return root->data;
    else
        (*strPath == 'L') ? getElement(root->left, strPath + 1) : getElement(root->right, strPath + 1);
}

void listLeaves(BinaryTree<int>::Node* root, std::vector<int>& ret)
{
    if(!root)
        return;

    listLeaves(root->left, ret);
    ret.push_back(root->data);
    listLeaves(root->right, ret);
}

void getVerticesOnLevels(BinaryTree<int>::Node* root, std::map<int, std::vector<int>> & map, int depth)
{
    if(!root)
        return;

    map[depth].push_back(root->data);
    getVerticesOnLevels(root->left, map, depth + 1);
    getVerticesOnLevels(root->right, map, depth + 1);
}

bool hasSameElementsOnDifferentLevels(BinaryTree<int>::Node* root)
{
    
}

bool isBOT(BinaryTree<int>::Node* root)
{
    if(!root || (root && !root->left && !root->right))
        return true;

    if(root->left && root->right)
        return (root->left->data < root->data && root->data < root->right->data) && isBOT(root->left) && isBOT(root->right);
    else if(root->left && !root->right)
        return (root->left->data < root->data) && isBOT(root->left);
    else if(root->right && !root->left)
        return (root->data < root->right->data) && isBOT(root->right);
}

int childNumRenameTree(BinaryTree<int>::Node* root)
{
    if(!root)
        return 0;

    return root->data = 1 + childNumRenameTree(root->right) + childNumRenameTree(root->left); 
}

int main()
{
    Node<int>* container = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, new Node<int>(5)))));
    Node<int>* evenContainer = new Node<int>(5);
    Node<int>* oddContainer = new Node<int>(6);

    mergeSplit(container, [](int num) {return num * 7;}, evenContainer, oddContainer);
    printList(evenContainer);
    printList(oddContainer);

    BinaryTree<int> bt(10, 
        new BinaryTree<int>(5),
        new BinaryTree<int>(20, 
            new BinaryTree<int>(15), 
            new BinaryTree<int>(25)));
    
    // Part01
    std::cout << "Total vertices: " << getCount(bt.getRoot()) << std::endl;
    std::cout << "Total evens count: " << getEvensCount(bt.getRoot()) << std::endl;
    std::cout << "Total vertices from predicate: " << searchCount(bt.getRoot(), [](int num) -> bool { return num % 5 == 0; }) << std::endl;
    std::cout << "Total height: " << getHeight(bt.getRoot()) << std::endl;
    std::cout << "Total leaves: " << getLeavesCount(bt.getRoot()) << std::endl;
    std::cout << "Max vertex value: " << getMaxLeaf(bt.getRoot()) << std::endl;
    std::cout << "Vertice with path: RL: " << getElement(bt.getRoot(), "RL") << std::endl;

    //Part02
    std::vector<int> ret;
    listLeaves(bt.getRoot(), ret);
    for(int i=0; i<ret.size(); ++i)
        std::cout << ret[i] << " ";
    std::cout << std::endl;

    std::map<int, std::vector<int>> map;
    getVerticesOnLevels(bt.getRoot(), map, 0);
    for(int i=0; i<map.size(); ++i)
    {
        std::vector<int>& currentVec = map[i];

        std::cout << "Level " << i << ": ";
        for(int j=0; j<currentVec.size(); ++j)
            std::cout << currentVec[j] << " ";
        std::cout << std::endl;
    }

    std::cout << "Is the tree BOT: " << (isBOT(bt.getRoot())?"Yes":"No") << std::endl;

    BinaryTree<int> bt1 = bt;
    childNumRenameTree(bt1.getRoot());
    std::vector<int> ret1;
    listLeaves(bt1.getRoot(), ret1);
    for(int i=0; i<ret1.size(); ++i)
        std::cout << ret1[i] << " ";
    std::cout << std::endl;

    return 0;
}