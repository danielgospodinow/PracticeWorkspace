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

    void add(T item);

    T get(int index);

    void insert(T item, int index);

    void remove(int index);

    bool contains(T item);

    void print();

private:
    void resize();

    T *_array;
    int _capacity;
    int _size;
};

template<typename T>
ArrayList<T>::ArrayList() : ArrayList(8) {}

template<typename T>
ArrayList<T>::ArrayList(int capacity) : _array(nullptr), _capacity(capacity), _size(0) {
    _array = new T[capacity];
}

template<typename T>
void ArrayList<T>::add(T item) {
    if (_size >= _capacity) {
        resize();
    }

    _array[_size++] = item;
}

template<typename T>
T ArrayList<T>::get(int index) {
    if (index < 0 || index >= _size) {
        throw std::invalid_argument("Index out of bounds");
    }

    return _array[index];
}

template<typename T>
void ArrayList<T>::insert(T item, int index) {
    if (index < 0 || index >= _size) {
        return;
    } else {
        if (_size >= _capacity) {
            resize();
        }

        ++_size;

        for (int i = _size - 1; i > index; --i) {
            _array[i] = _array[i - 1];
        }
        _array[index] = item;
    }
}

template<typename T>
void ArrayList<T>::remove(int index) {
    if (index < 0 || index >= _size) {
        return;
    } else {
        for (int i = index; i < _size - 1; ++i) {
            _array[i] = _array[i + 1];
        }

        --_size;
    }
}

template<typename T>
void ArrayList<T>::resize() {
    T *newStorage = new T[_capacity *= 2];

    for (int i = 0; i < _size; ++i) {
        newStorage[i] = _array[i];
    }

    T *oldStorage = _array;
    _array = newStorage;
    delete[] oldStorage;
}

template<typename T>
bool ArrayList<T>::contains(T item) {
    for (int i = 0; i < _size; ++i) {
        if (_array[i] == item) {
            return true;
        }
    }

    return false;
}

template<typename T>
void ArrayList<T>::print() {
    for (int i = 0; i < _size; ++i) {
        std::cout << get(i) << " ";
    }
    std::cout << std::endl;
}

#endif //DATASTRUCTURES_ARRAY_LIST_HPP
