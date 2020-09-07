//
// Created by Gospodinov, Daniel on 7.09.20.
//

#ifndef DATA_STRUCTURE_IMPLEMENTATIONS_BINARY_TREE_HPP
#define DATA_STRUCTURE_IMPLEMENTATIONS_BINARY_TREE_HPP

#include <iostream>
#include "algorithm"

template<typename T>
struct Node {
    T data;
    Node *left;
    Node *right;

    Node(T const &data, Node *left = nullptr, Node *right = nullptr) :
            data(data), left(left), right(right) {
    }
};

template<typename T>
class Tree {
private:
    Node<T> *root;

    void _erase(Node<T> *&rootNode) {
        if (!rootNode) {
            return;
        }

        _erase(rootNode->left);
        _erase(rootNode->right);
        delete rootNode;
        rootNode = nullptr;
    }

    void _copy(Node<T> *const source, Node<T> *&dest) {
        if (!source) {
            return;
        }

        dest = new Node<T>(source->data);
        _copy(source->left, dest->left);
        _copy(source->right, dest->right);
    }

    int _depth(Node<T> *rootNode) {
        if(!rootNode) {
            return 0;
        }

        return 1 + std::max(_depth(rootNode->left), _depth(rootNode->right));
    }

    void _preorderPrint(Node<T> *rootNode) {
        if(!rootNode) {
            return;
        }

        std::cout << rootNode->data << " ";
        _preorderPrint(rootNode->left);
        _preorderPrint(rootNode->right);
    }

public:
    Tree() : root(nullptr) {
    }

    Tree(Tree const &other) {
        _copy(other.root, root);
    }

    Tree &operator=(Tree const &other) {
        if (this != &other) {
            _erase(root);
            _copy(other.root, root);
        }

        return *this;
    }

    ~Tree() {
        _erase(root);
    }

    bool empty() {
        return !root;
    }

    int depth() {
        return _depth(root);
    }

    void preorderPrint() {
        _preorderPrint(root);
    }
};

#endif //DATA_STRUCTURE_IMPLEMENTATIONS_BINARY_TREE_HPP
