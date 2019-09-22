#ifndef LINKED_LIST_LINKED_LIST_HPP
#define LINKED_LIST_LINKED_LIST_HPP

#include <bits/exception.h>
#include <iostream>
#include <stdexcept>

template<typename T>
struct Node {
    explicit Node(T elem) {
        this->elem = elem;
        this->next = nullptr;
    }

    T elem;
    Node *next;
};

template<typename T>
class LinkedList {
public:
    LinkedList();

    void add(const T &item);

    T get(int index) const;

    void insert(const T &item, int index);

    void remove(const T &item);

    void removeAt(int index);

    bool contains(const T &item) const;

    int size() const;

    void print() const;

private:
    Node<T> *_head;
    Node<T> *_tail;
    int _size;
};

template<typename T>
LinkedList<T>::LinkedList():
        _head(nullptr),
        _tail(nullptr),
        _size(0) {
    // Initialize all class variables.
}

/**
 * Add a new item to the data structure.
 *
 * @tparam T type
 * @param item the new item
 */
template<typename T>
void LinkedList<T>::add(const T &item) {
    // Create a box which wraps the new element.
    auto *const newNode = new Node<T>(item);

    if (!_head) {
        // If the head is NULL then the data structure is empty,
        // so make the first element (the head) be the new element.
        // Do the same for the tail element.
        _head = newNode;
        _tail = newNode;

        // Increase the size of the data structure.
        ++_size;
    } else {
        // If the head is not null, then we have some elements
        // to work with and also the tail is not null.

        // Attach the new node to the last element (the tail) and
        // make it the new tail.
        _tail->next = newNode;
        _tail = newNode;

        // Increase the size of the data structure.
        ++_size;
    }
}

/**
 * Finds and returns an element by its index.
 *
 * @tparam T type
 * @param index index of the required element.
 * @return the element required
 */
template<typename T>
T LinkedList<T>::get(const int index) const {
    if (index < 0 || index >= _size) {
        // If the index is out of bounds, throw an exception.
        throw std::invalid_argument("Index out of bounds");
    } else {
        // Initialize an index counter and a pointer to the head element.
        int indexCounter = 0;
        Node<T> *iter = _head;

        // Move the pointer to point to the next element until we
        // reach the desired index.
        while (indexCounter++ < index) {
            iter = iter->next;
        }

        // Then return that exact item.
        return iter->elem;
    }
}

/**
 * Insert an element to the data structure at a specified index.
 *
 * @tparam T type
 * @param item item to insert
 * @param index index at which to insert
 */
template<typename T>
void LinkedList<T>::insert(const T &item, const int index) {
    if (index < 0 || index >= _size) {
        // If the index is out of bounds, throw an exception.
        throw std::invalid_argument("Index out of bounds");
    } else {
        // Create a box which wraps the new element.
        auto *const newNode = new Node<T>(item);

        // Initialize an index counter and two pointers to
        // track two consecutive elements.
        int indexCounter = 0;
        Node<T> *prev = nullptr;
        Node<T> *iter = _head;

        // While we haven't reached the desired index,
        // move both element pointers to the right.
        while (indexCounter++ < index) {
            prev = iter;
            iter = iter->next;
        }

        if (prev && iter) {
            // If we have both pointers pointing to an element,
            // then we're somewhere after the first element in the
            // data structure, so make the current element's previous
            // point to the new element and make the new element point
            // to the current one.
            prev->next = newNode;
            newNode->next = iter;

            // Increase the data structure's size.
            ++_size;
        } else if (iter) {
            // If only the pointer to the current element is
            // not null, then we're at the first element of the
            // data structure (the head), so make the new element
            // be the head and point it to the old head element.
            _head = newNode;
            _head->next = iter;

            // Increase the data structure's size.
            ++_size;
        }
    }
}

/**
 * Remove all elements from the data structure which match
 * the item provided.
 *
 * @tparam T type
 * @param item item to be removed
 */
template<typename T>
void LinkedList<T>::remove(const T &item) {
    // Initialize pointers to two consecutive elements
    // with the second one being the first element.
    Node<T> *prev = nullptr;
    Node<T> *curr = _head;

    // Iterate through all two consecutive elements while the second of the two
    // consecutive elements is not null.
    while (curr) {

        // If the current element's value is equal to the
        // value we're looking for.
        if (curr->elem == item) {

            // If the current element is the first element in the data structure,
            // then move the head with one position to the right.
            if (curr == _head) {

                // Check whether the head is equal to the tail.
                // If so, move the tail, essentially making it null.
                if (_head == _tail) {
                    _tail = _tail->next;
                }

                // Move the head element.
                _head = _head->next;
            }

            // If the current element's previous element is not null,
            // move it to the right.
            if (prev) {
                prev->next = curr->next;
            }

            if (curr == _tail) {
                // If we happen to remove the last element,
                // we should make the previous element the tail.
                _tail = prev;
                delete curr;
            } else {
                // Connect the current element's previous with the next element
                // in the data structure and delete the current one.
                Node<T> *temp = curr;
                curr = curr->next;
                delete temp;
            }

            // Reduce the size of the data structure.
            --_size;
        } else {
            // If the current element's value is not equal
            // to the value we're looking for, then just move both
            // elements with one position to the right.
            prev = curr;
            curr = curr->next;
        }
    }
}

/**
 * Remove an element from a specified index.
 *
 * @tparam T type
 * @param index index of an element
 */
template<typename T>
void LinkedList<T>::removeAt(const int index) {
    if (index < 0 || index >= _size) {
        // If the index is out of bounds, throw an exception.
        throw std::invalid_argument("Index out of bounds");
    } else {
        // Create an index counter and two pointers which
        // we'll use to keep track of every two consecutive
        // elements in the data structure.
        int indexCounter = 0;
        Node<T> *prev = nullptr;
        Node<T> *iter = _head;

        // Iterate through elements util
        // the desired element index is reached.
        while (indexCounter++ < index) {
            prev = iter;
            iter = iter->next;
        }

        if (prev && iter) {
            // If both consecutive elements exist this means
            // that we're surely somewhere after the first
            // element.

            // Check whether we're trying to delete the last element.
            // If so, make the previous the new tail.
            if(iter == _tail) {
                _tail = prev;
            }

            // Break the connection between the two consecutive
            // elements and make the first one point to the
            // second one's next element, thus preparing the
            // second element for deletion.
            prev->next = iter->next;

            // Reduce the size of the data structure by 1 and
            // delete the second of the two consecutive elements.
            --_size;
            delete iter;
        } else if (iter) {
            // If only the second of the two consecutive elements
            // exist, this means that we're at the beginning of
            // the data structure. In this case we need to move
            // the head with one position.
            _head = _head->next;

            // Reduce the size of the data structure by 1 and
            // delete the second of the two consecutive elements.
            --_size;
            delete iter;
        }
    }
}

/**
 * Checks whether an element is present in the data structure.
 *
 * @tparam T type
 * @param item item to check for
 * @return true if the item is present, false otherwise
 */
template<typename T>
bool LinkedList<T>::contains(const T &item) const {
    // Initialize a pointer to the head element.
    Node<T> *iter = _head;

    while (iter) {
        // While the current element exists, check whether its element
        // is equal to the one we're looking for and return true if
        // that's the case.
        if (iter->elem == item) {
            return true;
        }

        // If we don't match, move the current element pointer to the
        // next one.
        iter = iter->next;
    }

    // Return false if we haven't got any matches.
    return false;
}

template<typename T>
int LinkedList<T>::size() const {
    // Return the size of the data structure.
    return _size;
}

template<typename T>
void LinkedList<T>::print() const {
    Node<T> *iter = _head;

    while (iter) {
        std::cout << iter->elem << " ";

        iter = iter->next;
    }
    std::cout << std::endl;
}

#endif //LINKED_LIST_LINKED_LIST_HPP
