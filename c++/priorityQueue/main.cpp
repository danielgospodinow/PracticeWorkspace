#include <iostream>
using namespace std;

#include "priorityqueue.hpp"

int main()
{
    PriorityQueue<int> queue;

    queue.push(5, 0);
    queue.push(6, 16);
    queue.push(7, 2);
    queue.push(8, 4);
    queue.push(70, 70);

    queue.print();

    cout << queue.peek() << endl;

    for(int i=0; i<5; i++)
    {
        cout << queue.pop() << endl;
    }

    queue.push(5, 15);
    queue.push(6, 16);
    queue.print();

    return 0;
}
