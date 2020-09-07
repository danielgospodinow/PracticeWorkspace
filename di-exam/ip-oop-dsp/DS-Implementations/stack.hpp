//
// Created by Gospodinov, Daniel on 7.09.20.
//

#ifndef DATA_STRUCTURE_IMPLEMENTATIONS_STACK_HPP
#define DATA_STRUCTURE_IMPLEMENTATIONS_STACK_HPP

const int MAX = 100;

template<typename T>
class Stack {
public:
    Stack() : _top(-1) {
    }

    bool push(T const &item) {
        if (full()) {
            return false;
        }

        _items[++_top] = item;
        return true;
    }

    T pop() {
        if (empty()) {
            return T();
        }

        return _items[_top--];
    }

    T peek() const {
        if (empty()) {
            return T();
        }

        return _items[_top];
    }

private:
    T _items[MAX];
    int _top;

    bool full() {
        return _top == MAX - 1;
    }

    bool empty() const {
        return _top == -1;
    }
};

#endif //DATA_STRUCTURE_IMPLEMENTATIONS_STACK_HPP
