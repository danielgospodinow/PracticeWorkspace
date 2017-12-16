#ifndef BROWSER_HPP
#define BROWSER_HPP

#include "doublelinkedlist.hpp"
#include "tab.hpp"
#include <vector>
#include <algorithm>

class Browser
{
public:

    Browser();

    void start();

private:

    std::vector<std::string> splitter(std::string str);
    void toLower(std::string& str);

    DoubleLinkedList<Tab> _dll;
    DoubleLinkedListIterator<Tab> _navigator;
};

#endif
