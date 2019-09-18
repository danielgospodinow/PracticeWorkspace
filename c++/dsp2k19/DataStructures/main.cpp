#include <iostream>

#include "data_structures/linked_list/linked_list.hpp"
#include "data_structures/array_list/array_list.hpp"

int main() {
    LinkedList<int> linkedList = LinkedList<int>();
    linkedList.add(5);
    linkedList.add(7);
    linkedList.add(19);
    linkedList.print();

    ArrayList<int> arrayList = ArrayList<int>();
    arrayList.add(9);
    arrayList.add(22);
    arrayList.add(77);
    arrayList.insert(69, 2);
    arrayList.remove(2);
    arrayList.insert(66, 0);
    arrayList.remove(1);
    arrayList.print();

    std::cout << arrayList.get(1) << std::endl;

    std::cout << arrayList.contains(11) << std::endl;

    return 0;
}