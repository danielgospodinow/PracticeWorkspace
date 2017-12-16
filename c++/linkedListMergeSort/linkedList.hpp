#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class LinkedList
{
public:
    LinkedList():
        _first(nullptr), _last(nullptr), _size(0)
    {
    }

    void add(const T& el)
    {
        Node<T>* newEl = new Node<T>(el, nullptr);
        ++_size;

        if(isEmpty())
        {
            _first = newEl;
            _last = _first;

            return;
        }

        _last->next = newEl;
        _last = _last->next;
    }

    T remove(int index)
    {
        if(index <= -1 || index >= _size)
        {
            cout << "Invalid removal!" << endl;
            return T();
        }

        --_size;

        if(index == 0)
        {
            Node<T>* toDel = _first;
            T ret = toDel->data;
            _first = _first->next;
            delete toDel;

            return ret;
        }
        else
        {
            Node<T>* iter = _first;
            for(int i=0; i<index - 1; i++)
                iter = iter->next;

            Node<T>* toDel = iter->next;
            T ret = toDel->data;
            iter->next = iter->next->next;
            delete toDel;

            return ret;
        }
    }

    void sort()
    {
        mergeSort(_first, _last);
    }

    void print() const
    {
        if(isEmpty())
        {
            cout << "Empty list!" << endl;
            return;
        }

        Node<T>* iter = _first;
        while(iter)
        {
            cout << iter->data << " ";
            iter = iter->next;
        }
        cout << endl;
    }

    bool isEmpty() const {return !_first;}
    int getSize() const {return _size;}

private:
    LinkedList(const LinkedList& other) {}
    void operator= (const LinkedList& other) {}

    template <class R>
    struct Node
    {
        Node(R _data, Node* _next):
           next(_next), data(_data)
        {
        }

        Node* next;
        R data;
    };

    void mergeSort(Node<T>* start, Node<T>* end)
    {
        if(start == end)
            return;

        Node<T>* middlePoint = getMiddleElement(start, end);

        mergeSort(start, middlePoint);
        mergeSort(middlePoint->next, end);

        merge(start, middlePoint, middlePoint->next, end);
    }

    void merge(Node<T>* start01, Node<T>* end01, Node<T>* start02, Node<T>* end02)
    {
        LinkedList<T> tempLl;

        Node<T> *iter01 = start01, *iter02 = start02;

        auto iter01Call = [&]()
        {
            tempLl.add(iter01->data);
            iter01 = iter01->next;
        };

        auto iter02Call = [&]()
        {
            tempLl.add(iter02->data);
            iter02 = iter02->next;
        };

        while(iter01 != end01->next && iter02 != end02->next)
        {
            if(iter01->data <= iter02->data)
                iter01Call();
            else
                iter02Call();
        }

        while(iter01 != end01->next)
            iter01Call();

        while(iter02 != end02->next)
            iter02Call();

        Node<T>* fillIter = start01;
        while(!tempLl.isEmpty())
        {
            fillIter->data = tempLl.remove(0);
            fillIter = fillIter->next;
        }
    }

    Node<T>* getMiddleElement(Node<T>* start, Node<T>* end)
    {
        Node<T> *slowPointer = start, *fastPointer = start;

        auto canJump = [&]()
        {
            return fastPointer && fastPointer->next->next && fastPointer->next->next != end && fastPointer->next->next != end->next;
        };

        while(canJump())
        {
            fastPointer = fastPointer->next->next;
            slowPointer = slowPointer->next;
        }

        return slowPointer;
    }

    Node<T> *_first, *_last;
    int _size;
};

#endif
