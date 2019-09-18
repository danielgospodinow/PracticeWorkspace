#ifndef LINKED_LIST_LINKED_LIST_HPP
#define LINKED_LIST_LINKED_LIST_HPP

template<typename T>
struct Node {
    explicit Node(T elem) {
        this->elem = elem;
        this->next = nullptr;
    }

    T elem;
    Node *next;
};

template<typename T>
class LinkedList {
public:
    LinkedList();

    void print();

    void add(T item);

    void remove(T item);

private:
    Node<T> *_head = nullptr;
    Node<T> *_tail = nullptr;
};

template<typename T>
LinkedList<T>::LinkedList() = default;

template<typename T>
void LinkedList<T>::add(T item) {
    auto *newNode = new Node<T>(item);

    if (!_head) {
        _head = newNode;
    } else {
        Node<T> *iter = _head;
        while (iter->next) {
            iter = iter->next;
        }
        iter->next = newNode;
    }
}

template<typename T>
void LinkedList<T>::remove(T item) {
    Node<T> *iter = _head;

    if (iter) {
        Node<T> *prevElem = iter;

        while (iter) {
            if (iter->elem == item) {
                if (iter == _head) {
                    _head = _head->next;
                }

                prevElem->next = iter->next;
                delete iter;

                iter = prevElem->next;
            }

            prevElem = iter;
            iter = prevElem->next;
        }
    }
}

template<typename T>
void LinkedList<T>::print() {
    Node<T> *iter = _head;

    while (iter) {
        std::cout << iter->elem << " ";

        iter = iter->next;
    }
    std::cout << std::endl;
}

#endif //LINKED_LIST_LINKED_LIST_HPP
