#ifndef TAB_HPP
#define TAB_HPP

#include <iostream>
#include <string>
#include <ctime>

class Tab
{
public:
    enum SortTypes {ByURL, ByTime};
    static SortTypes sortType;

    Tab(std::string name = "about:blank");

    bool operator <= (Tab const& other)
    {
        switch (sortType)
        {
        case SortTypes::ByTime:

            if(this->_dateTime != other._dateTime)
                return (this->_dateTime < other._dateTime);
            else
                return (this->_name.compare(other._name) <= 0);

        case SortTypes::ByURL:

            short strCmpRes = this->_name.compare(other._name);

            if(strCmpRes != 0)
                return (strCmpRes < 0);
            else
                return (this->_dateTime <= other._dateTime);
        }
    }

    friend std::ostream& operator << (std::ostream& os, Tab const& tab)
    {
        os << tab._name << " " << tab._dateTime;
        return os;
    }

private:

    std::string _name;
    std::time_t _dateTime;
};

#endif
