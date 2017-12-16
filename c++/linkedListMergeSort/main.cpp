#include <iostream>
using namespace std;

#include "linkedList.hpp"

int main()
{
    LinkedList<int> ll;
    for(int i=0; i<15; i++)
        ll.add(rand() % 100 + 1);

    ll.print();

    ll.sort();
    ll.print();

    return 0;
}
