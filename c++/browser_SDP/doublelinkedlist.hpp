#ifndef DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_HPP

template <class T>
struct DoubleLinkedListElem;

template <class T>
class DoubleLinkedListIterator;

template <class T>
class DoubleLinkedList
{
public:
    DoubleLinkedList():
        _front(nullptr), _back(nullptr)
    {
    }

    void insert(T const& data)
    {
        DoubleLinkedListElem<T>* newData = new DoubleLinkedListElem<T>(data);

        if(!_back && !_front)
        {
            _front = (_back = newData);
            return;
        }

        _front->next = newData;
        newData->prev = _front;
        _front = newData;
    }

    void insert(T const& data, DoubleLinkedListIterator<T> const& it)
    {
        DoubleLinkedListElem<T>* newData = new DoubleLinkedListElem<T>(data);

        if(!_back && !_front)
        {
            _front = (_back = newData);
            return;
        }

        if(!it._current->next)
        {
            it._current->next = newData;
            newData->prev = it._current;
            _front = newData;
            return;
        }

        newData->next = it._current->next;
        it._current->next->prev = newData;
        newData->prev = it._current;
        it._current->next = newData;
    }

    T remove(DoubleLinkedListIterator<T>& it)
    {
        if(isEmpty())
            return T();

        T ret = *it;
        DoubleLinkedListElem<T>* toDel = it.getElem();

        if (it.getElem()->prev && it.getElem()->next)
        {
            it.getElem()->prev->next = it.getElem()->next;
            it.getElem()->next->prev = it.getElem()->prev;

            it._current = it.getElem()->next;
        }
        else if(it.getElem()->prev)
        {
            _front = it.getElem()->prev;
            _front->next = nullptr;
            it._current = _front;
        }
        else if(it.getElem()->next)
        {
            _back = it.getElem()->next;
            _back->prev = nullptr;
            it._current = _back;
        }
        else
        {
            _back = (_front = nullptr);
        }

        delete toDel;
        toDel = nullptr;

        return ret;
    }

    void sort()
    {
        mergeSort(_back, _front);
    }

    bool isEmpty() {return !_front && !_back;}

    DoubleLinkedListIterator<T> begin() const
    {
        return DoubleLinkedListIterator<T>(_back);
    }

    DoubleLinkedListIterator<T> end() const
    {
        return DoubleLinkedListIterator<T>(_front);
    }

private:
    void mergeSort(DoubleLinkedListElem<T>* start, DoubleLinkedListElem<T>* end)
    {
        if(start == end)
            return;

        DoubleLinkedListElem<T>* middlePoint = getMiddleElement(start, end);

        mergeSort(start, middlePoint);
        mergeSort(middlePoint->next, end);

        merge(start, middlePoint, middlePoint->next, end);
    }

    void merge(DoubleLinkedListElem<T>* start01, DoubleLinkedListElem<T>* end01, DoubleLinkedListElem<T>* start02, DoubleLinkedListElem<T>* end02)
    {
        DoubleLinkedList<T> tempLl;

        DoubleLinkedListElem<T> *iter01 = start01, *iter02 = start02;

        auto iter01Call = [&]()
        {
            tempLl.insert(iter01->data);
            iter01 = iter01->next;
        };

        auto iter02Call = [&]()
        {
            tempLl.insert(iter02->data);
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

        DoubleLinkedListElem<T>* fillIter = start01;
        while(!tempLl.isEmpty())
        {
            DoubleLinkedListIterator<T> tempIt = tempLl.begin();
            fillIter->data = tempLl.remove(tempIt);
            fillIter = fillIter->next;
        }
    }

    DoubleLinkedListElem<T>* getMiddleElement(DoubleLinkedListElem<T>* start, DoubleLinkedListElem<T>* end)
    {
        DoubleLinkedListElem<T> *slowPointer = start, *fastPointer = start;

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


    DoubleLinkedListElem<T> *_front, *_back;
};

template <class T>
struct DoubleLinkedListElem
{
    DoubleLinkedListElem(T const& _data, DoubleLinkedListElem<T>* _prev = nullptr, DoubleLinkedListElem<T>* _next = nullptr):
        data(_data), prev(_prev), next(_next)
    {
    }

    T data;
    DoubleLinkedListElem<T> *prev, *next;
};

template <class T>
class DoubleLinkedListIterator
{
public:
    friend class DoubleLinkedList<T>;

    DoubleLinkedListIterator(DoubleLinkedListElem<T>* elem = nullptr):
        _current(elem)
    {
    }

    T& operator * () const
    {
        return _current->data;
    }

    DoubleLinkedListElem<T>* getElem()
    {
        return _current;
    }

    operator bool() const
    {
        return _current != nullptr;
    }

    DoubleLinkedListIterator<T> operator ++ (int)
    {
        DoubleLinkedListIterator<T> ret = *this;
        next();
        return ret;
    }

    DoubleLinkedListIterator<T>& operator ++ ()
    {
        next();
        return *this;
    }

    DoubleLinkedListIterator<T> operator -- (int)
    {
        DoubleLinkedListIterator<T> ret = *this;
        previous();
        return ret;
    }

    DoubleLinkedListIterator<T>& operator -- ()
    {
        previous();
        return *this;
    }

    void next()
    {
        _current = _current->next;
    }

    void previous()
    {
        _current = _current->prev;
    }

private:
    DoubleLinkedListElem<T> *_current;
};

#endif
