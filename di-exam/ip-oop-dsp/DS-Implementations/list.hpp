//
// Created by Gospodinov, Daniel on 7.09.20.
//

#ifndef DATA_STRUCTURE_IMPLEMENTATIONS_LIST_HPP
#define DATA_STRUCTURE_IMPLEMENTATIONS_LIST_HPP

template<typename T>
struct Item {
    Item(T const &data, Item *next = nullptr) :
            data(data), next(next) {
    }

    T data;
    Item *next;
};

template<typename T>
class List {
private:
    Item<T> *start, *end;

    void erase() {
        Item<T> *temp;
        while (start) {
            temp = start;
            start = start->next;
            delete temp;
        }
        end = nullptr;
    }

    void copy(List const &other) {
        Item<T> *iter = other.start;
        while (iter) {
            add(iter->data);
            iter = iter->next;
        }
    }

public:
    List() : start(nullptr), end(nullptr) {}

    List(List const &other) {
        copy(other);
    }

    List &operator=(List const &other) {
        if (this != &other) {
            erase();
            copy(other);
        }

        return *this;
    }

    ~List() {
        erase();
    }

    void insertEnd(T const &data) {
        if (empty()) {
            insertBegin(data);
            return;
        }

        Item<T> *item = new Item(data);
        end->next = item;
        end = item;
    }

    void insertBegin(T const &data) {
        Item<T> *item = new Item(data, start);

        if (empty()) {
            end = item;
        }
        start = item;
    }

    void insertAt(int index, T const &data) {
        if (index == 0) {
            insertBegin(data);
            return;
        }

        int iterNum = 0;
        Item<T> *iterPtr = start;
        Item<T> *prev = nullptr;

        while (iterNum != index && iterPtr != nullptr) {
            ++iterNum;
            prev = iterPtr;
            iterPtr = iterPtr->next;
        }

        if (iterPtr == nullptr) {
            insertEnd(data);
        } else {
            Item<T> *item = new Item(data, iterPtr);
            prev->next = item;
        }
    }

    void deleteAt(int index) {
        int numIter = 0;
        Item<T> *current = start;
        Item<T> *prev = nullptr;

        while (numIter != index && current != nullptr) {
            ++numIter;
            prev = current;
            current = current->next;
        }

        if (!current) {
            return;
        } else {
            if (index == 0) {
                Item<T> *del = start;
                start = start->next;
                if (!start) {
                    end = nullptr;
                }
                delete del;
            } else {
                Item<T> *del = current;
                prev->next = current->next;
                delete del;
            }
        }
    }

    bool empty() {
        return (!start && !end);
    }
};

#endif //DATA_STRUCTURE_IMPLEMENTATIONS_LIST_HPP
