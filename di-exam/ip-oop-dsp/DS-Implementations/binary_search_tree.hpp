//
// Created by Gospodinov, Daniel on 7.09.20.
//

#ifndef DATA_STRUCTURE_IMPLEMENTATIONS_BINARY_SEARCH_TREE_HPP
#define DATA_STRUCTURE_IMPLEMENTATIONS_BINARY_SEARCH_TREE_HPP

#include <iostream>

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

    void _printSorted(Node<T> *rootNode) {
        if (!rootNode) {
            return;
        }

        _printSorted(rootNode->left);
        std::cout << rootNode->data << " ";
        _printSorted(rootNode->right);
    }

    void _addElement(Node<T> *&rootNode, T const &elem) {
        if (!rootNode) {
            rootNode = new Node<T>(elem);
            return;
        }

        if (elem < rootNode->data) {
            _addElement(rootNode->left, elem);
        } else if (elem > rootNode->data) {
            _addElement(rootNode->right, elem);
        }
    }

    void _deleteElement(Node<T> *&rootNode, T const &elem) {
        if (!rootNode) {
            return;
        }

        if (elem < rootNode->data) {
            _deleteElement(rootNode->left, elem);
        } else if (elem > rootNode->data) {
            _deleteElement(rootNode->right, elem);
        } else {
            if (!rootNode->left) {
                Node<T> *temp = rootNode;
                rootNode = rootNode->right;
                delete temp;
            } else if (!rootNode->right) {
                Node<T> *temp = rootNode;
                rootNode = rootNode->left;
                delete temp;
            } else {
                Node<T> *iter = rootNode->left;
                while(iter->right) {
                    iter = iter->right;
                }

                rootNode->data = iter->data;
                _deleteElement(rootNode->left, iter->data);
            }
        }
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

    void printSorted() {
        _printSorted(root);
    }

    void addElement(T const &elem) {
        _addElement(root, elem);
    }

    void deleteElement(T const &elem) {
        _deleteElement(root, elem);
    }
};

#endif //DATA_STRUCTURE_IMPLEMENTATIONS_BINARY_SEARCH_TREE_HPP
