#ifndef DATASTRUCTURES_ARRAY_LIST_HPP
#define DATASTRUCTURES_ARRAY_LIST_HPP

#include <bits/exception.h>
#include <iostream>
#include <stdexcept>

template<typename T>
class ArrayList {
public:
    ArrayList();

    explicit ArrayList(int capacity);

    void add(const T &item);

    void insert(const T &item, int index);

    void remove(const T &item);

    void removeAt(int index);

    T get(int index) const;

    bool contains(const T &item) const;

    int size() const;

    void print() const;

private:
    void resize();

    T *_array;
    int _capacity;
    int _size;
};

template<typename T>
ArrayList<T>::ArrayList(const int capacity) :
        _array(nullptr),
        _capacity(capacity),
        _size(0) {
    // Initialize all class variables.
    _array = new T[_capacity];
}

template<typename T>
ArrayList<T>::ArrayList() : ArrayList(8) {
    // If no capacity is specified, use 8 as a default initial value
    // and delegate the initialization to the constructor above.
}

/**
 * Add a new item to the data structure.
 * @tparam T type
 * @param item item to add
 */
template<typename T>
void ArrayList<T>::add(const T &item) {
    // Check if there's a need to make additional space.
    if (_size >= _capacity) {
        resize();
    }

    // Add the item to the data structure and increase the size by 1.
    _array[_size++] = item;
}

/**
 * Finds and returns an element by its index.
 *
 * @tparam T type
 * @param index index of the required element.
 * @return the element required
 */
template<typename T>
T ArrayList<T>::get(const int index) const {
    if (index < 0 || index >= _size) {
        // If the index is out of bounds, throw an exception.
        throw std::invalid_argument("Index out of bounds");
    } else {
        // Retrieve the element from the specified index.
        return _array[index];
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
void ArrayList<T>::insert(const T &item, const int index) {
    if (index < 0 || index >= _size) {
        // If the index is out of bounds, throw an exception.
        throw std::invalid_argument("Index out of bounds");
    } else {
        // Check if there's a need to make additional space.
        if (_size >= _capacity) {
            resize();
        }

        // Increase the size of the data structure.
        // Note: It's important to do this here, before the for-loop
        // below, because the loop needs to shift some elements with one
        // position to the right.
        ++_size;

        // Shift all elements from the end down to the provided index
        // with one position to the right.
        for (int i = _size - 1; i > index; --i) {
            _array[i] = _array[i - 1];
        }

        // Assign the new element.
        _array[index] = item;
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
void ArrayList<T>::remove(const T &item) {
    // Iterate through all elements and remove those
    // who are equal to the one provided.
    for (int i = 0; i < _size; ++i) {
        if (_array[i] == item) {
            removeAt(i);
            
            // Reduce the iterator variable in order
            // to stay at the same place after an element
            // remove operation.
            --i;
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
void ArrayList<T>::removeAt(const int index) {
    if (index < 0 || index >= _size) {
        // If the index is out of bounds, throw an exception.
        throw std::invalid_argument("Index out of bounds");
    } else {
        // Shift all elements from the provided index up to the last one
        // with one position to the left.
        for (int i = index; i < _size - 1; ++i) {
            _array[i] = _array[i + 1];
        }

        // Reduce the size of the data structure.
        --_size;
    }
}

/**
 * Double the size of the data structure.
 *
 * @tparam T type
 */
template<typename T>
void ArrayList<T>::resize() {
    // Create the new bigger array with double the size of the old one.
    T *const newStorage = new T[_capacity *= 2];

    // Copy all the elements from the old array to the new one.
    for (int i = 0; i < _size; ++i) {
        newStorage[i] = _array[i];
    }

    // Make the bigger array to be the current array of
    // the data structure and clear the old one.
    T *oldStorage = _array;
    _array = newStorage;
    delete[] oldStorage;
}

/**
 * Checks whether an element is present in the data structure.
 *
 * @tparam T type
 * @param item item to check for
 * @return true if the item is present, false otherwise
 */
template<typename T>
bool ArrayList<T>::contains(const T &item) const {
    // Iterate through all elements and return 'true'
    // if an element matches the provided one.
    for (int i = 0; i < _size; ++i) {
        if (_array[i] == item) {
            return true;
        }
    }

    // Return 'false' otherwise.
    return false;
}

template<typename T>
int ArrayList<T>::size() const {
    // Return the size of the data structure.
    return _size;
}

template<typename T>
void ArrayList<T>::print() const {
    // Iterate through all elements and print
    // them to the console.

    for (int i = 0; i < _size; ++i) {
        std::cout << get(i) << " ";
    }
    std::cout << std::endl;
}

#endif //DATASTRUCTURES_ARRAY_LIST_HPP
