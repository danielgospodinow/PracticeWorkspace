//
// Created by Gospodinov, Daniel on 7.09.20.
//

#ifndef DATA_STRUCTURE_IMPLEMENTATIONS_QUEUE_HPP
#define DATA_STRUCTURE_IMPLEMENTATIONS_QUEUE_HPP

template<typename T>
struct QueueElement {
    QueueElement(T const &data, QueueElement *next = nullptr) :
            data(data), next(next) {
    }

    T data;
    QueueElement *next;
};

template<typename T>
class Queue {
public:
    Queue() : front(nullptr), rear(nullptr) {
    }

    Queue(Queue const &other) : Queue() {
        copy(other);
    }

    Queue &operator=(Queue const &other) {
        if (this != &other) {
            erase();
            copy(other);
        }

        return *this;
    }

    ~Queue() {
        erase();
    }

    void enqueue(T const &elem) {
        QueueElement<T> *queueElement = new QueueElement<T>(elem);

        if (rear) {
            rear->next = queueElement;
        } else {
            front = queueElement;
        }

        rear = queueElement;
    }

    T dequeue() {
        if (empty()) {
            return T();
        }

        QueueElement<T> *frontMemory = front;

        front = front->next;
        if (!front) {
            rear = nullptr;
        }

        T ret = frontMemory->data;
        delete frontMemory;

        return ret;
    }

    T head() {
        if (empty()) {
            return T();
        }

        return front->data;
    }

private:
    QueueElement<T> *front, *rear;

    bool empty() const {
        return (!front && !rear);
    }

    void copy(Queue const &otherQueue) {
        QueueElement<T> *iter = otherQueue.front;
        while (iter) {
            enqueue(iter->data);

            iter = iter->next;
        }
    }

    void erase() {
        while (!empty()) {
            dequeue();
        }
    }
};

#endif //DATA_STRUCTURE_IMPLEMENTATIONS_QUEUE_HPP
