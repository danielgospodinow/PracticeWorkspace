#include "tab.hpp"

Tab::SortTypes Tab::sortType = Tab::SortTypes::ByTime;

Tab::Tab(std::string name):
    _name(name)
{
    _dateTime = std::time(0);
}
