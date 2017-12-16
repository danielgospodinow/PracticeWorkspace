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
        _last(nullptr)
    {
    }

    void push(T const& newElement)
    {
        ListElement<T>* newLast = new ListElement<T>(newElement, _last);
        _last = newLast;
    }

    T pop()
    {
        if(!_last)
            return T();

        T ret = _last->data;
        ListElement<T>* del = _last;
        _last = _last->nextElement;

        delete del;
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

        cout << endl;
    }

private:
    ListElement<T>* _last;
};

int main()
{
    LinkedStack<int> ls;

    ls.push(7);
    ls.push(19);
    ls.push(21);

    ls.print();

    int g = ls.peek();

    return 0;
}
