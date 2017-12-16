#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

typedef unsigned int uint;

template <typename T>
class PriorityQueue
{
public:
    PriorityQueue():
        _first(nullptr), _last(nullptr)
    {}

    void push(const T& data, int priority)
    {
        if(isEmpty())
        {
            _first = new PriorityQueueNode<T> (data, nullptr, priority);
            _last = _first;
            return;
        }

        PriorityQueueNode<T>* newEl = new PriorityQueueNode<T>(data, nullptr, priority);

        if(newEl->priority > _first->priority)
        {
            PriorityQueueNode<T>* temp = _first;
            _first = newEl;
            newEl->next = temp;
        }
        else
        {
            PriorityQueueNode<T>* iter = _first;
            while(iter->next)
            {
                if(newEl->priority <= iter->priority && newEl->priority >= iter->next->priority)
                {
                    PriorityQueueNode<T>* temp = iter->next;
                    iter->next = newEl;
                    newEl->next = temp;

                    return;
                }

                iter = iter->next;
            }

            _last->next = newEl;
            _last = _last->next;
        }
    }

    T pop()
    {
        if(isEmpty())
        {
            cout << "Empty!\n";
            throw 1;
        }

        T ret = _first->data;

        PriorityQueueNode<T>* toDel = _first;
        _first = _first->next;
        delete toDel;

        return ret;
    }

    const T& peek()
    {
        if(isEmpty())
        {
            cout << "Empty queue!";
            throw 1;
        }

        return _first->data;
    }

    bool isEmpty()
    {
        return !_first;
    }

    void print()
    {
        PriorityQueueNode<T>* iter = _first;
        while(iter)
        {
            cout << iter->data << " ";
            iter = iter->next;
        }
        cout << endl;
    }

private:
    template <typename R>
    struct PriorityQueueNode
    {
        PriorityQueueNode(R data, PriorityQueueNode* next, int priority){this->data = data; this->next = next; this->priority = priority;}

        PriorityQueueNode* next;
        R data;
        uint priority;
    };

    PriorityQueueNode<T>* _first;
    PriorityQueueNode<T>* _last;
};

#endif
