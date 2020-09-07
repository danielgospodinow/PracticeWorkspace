#include <iostream>
#include "stack.hpp"
#include "queue.hpp"

void stackTest();
void queueTest();

int main() {
//    stackTest();
//    queueTest();

    return 0;
}

void queueTest() {
    Queue<int> queue;
    queue.enqueue(2);
    queue.enqueue(22);
    queue.enqueue(222);

    for(int i=0; i<3; ++i) {
        std::cout << queue.dequeue() << std::endl;
    }

    std::cout << queue.head() << std::endl;
}

void stackTest() {
    Stack<int> stack;
    stack.push(15);
    stack.push(71);
    stack.push(22);

    for(int i=0; i<3; ++i) {
        std::cout << stack.pop() << std::endl;
    }

    std::cout << stack.peek() << std::endl;
}
