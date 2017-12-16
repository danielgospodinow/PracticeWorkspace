#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include <iostream>
using namespace std;

template <typename T>
struct ListElement
{
    ListElement(T _data, ListElement<T>* _nextEle):
        data(_data), nextElement(_nextEle)
    {
    }

    T data;
    ListElement<T>* nextElement;
};

template <typename T>
class LinkedStack
{
public:
    LinkedStack():
        _last(nullptr), _size(0)
    {
    }

    void push(T const& newElement)
    {
        ListElement<T>* newLast = new ListElement<T>(newElement, _last);
        _last = newLast;
        ++_size;
    }

    T pop()
    {
        if(!_last)
            return T();

        T ret = _last->data;
        ListElement<T>* del = _last;
        _last = _last->nextElement;

        delete del;
        --_size;
        return ret;
    }

    T const& peek()
    {
        //fix _last nullptr bug

        return _last->data;
    }

    void print()
    {
        ListElement<T>* iter = _last;
        while(iter)
        {
            cout << iter->data <<" ";

            iter = iter->nextElement;
        }
    }

    int getSize() {return _size;}

private:
    ListElement<T>* _last;
    int _size;
};

#endif
